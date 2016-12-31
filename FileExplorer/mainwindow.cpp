#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "aboutform.h"
#include "qfexpath.h"
#include "qfexfile.h"
#include "QPushButton"
#include "QIcon"
#include "QFileSystemModel"
#include "QTreeWidgetItem"
#include "searchform.h"
#include "fileproperties.h"
#include <QMessageBox>
#include <QInputDialog>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    clipboardFiles = new QList<QFileInfo>();
    clipboardFilesRemove = false;
    isListerTextChanged = false;


    //QMainWindow::centralWidget()->layout()->setContentsMargins(0, 0, 0, 0);
    this->layout()->setContentsMargins(0, 0, 0, 0);
    const QSize *gridSize = new QSize(100,100);
    ui->listView->setGridSize(*gridSize);

    /* set up dock widget objects */
    QWidget* titleWidget = new QWidget(this);
    ui->dockWidget->setTitleBarWidget( titleWidget );
    ui->dockWidgetLister->setContentsMargins(0, 0, 0, 0);

    currentPath = QFeXPath::getRootPath();

    /*get initial directories*/
    modelDirectories = new QFileSystemModel(this);
    modelDirectories->setRootPath(currentPath);
    modelDirectories->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs); //filter directories only and hide ".." folders
    ui->treeView->setModel(modelDirectories);
    //display only Name, hide the other columns (Size, Type, Date Modified)
    for(int nCount = 1; nCount < modelDirectories->columnCount(); nCount++)
    {
        ui->treeView->hideColumn(nCount);
    }


    /*get initial file list*/
    modelFiles = new QFileSystemModel(this);
    modelFiles->setRootPath(currentPath);
    //modelFiles->setFilter(QDir::NoDotAndDotDot | QDir::Files | QDir::Hidden); //filter files only and hide ".." folders
    ui->listView->setModel(modelFiles);


    //set List View context menu
    ui->listView->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->listView, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(showFileContextMenu(QPoint)));

    //set Lister context menu
    ui->textEdit->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->textEdit,SIGNAL(customContextMenuRequested(const QPoint&)), this,SLOT(showExtendedListerContextMenu(const QPoint &)));
    connect(ui->textEdit, SIGNAL(textChanged()), this, SLOT(enableExtendedListerContextMenuSaveAction()));

    //connect click & double click signals
    connect(ui->listView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(itemDoubleClicked(QModelIndex)));

    //style the main menu
    ui->menuBar->setStyleSheet("QMenuBar {background-color: rgb(51, 51, 51);border-bottom-color: rgb(0, 0, 0);border-color: rgb(0, 170, 255);color: rgb(238, 238, 238); padding: 2px 5px 2px 5px;}  "
                               "QMenuBar:item:selected {background-color: #666; color:#fff;}  "
                               "QMenu {background-color: #666; color:#fff;} "
                               "QMenu::item:selected {background-color: #333;}");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_action_Search_triggered()
{
    SearchForm *sf = new SearchForm(this);
    sf->setCurrentPath(currentPath);
    sf->show();
}

void MainWindow::on_actionAbout_triggered()
{
    AboutForm *ab = new AboutForm(this);
    ab->show();
}

void MainWindow::on_actionShow_Treeview_toggled(bool arg1)
{

    //Slide menu
    if(arg1!=true)
    {
        ui->dockWidget->hide();
    }
    else
    {
        ui->dockWidget->show();
    }
}

void MainWindow::on_actionLister_toggled(bool arg1)
{
    //Slide menu
    if(arg1!=true)
    {
        ui->dockWidgetLister->hide();
    }
    else
    {
        ui->dockWidgetLister->show();
    }
}

void MainWindow::on_dockWidgetLister_visibilityChanged(bool visible)
{
    ui->actionLister->setChecked(visible);
}

/*Set Selected Root Path*/
void MainWindow::on_treeView_clicked(const QModelIndex &index)
{
    //extract the path from the current node
    currentPath = modelDirectories->fileInfo(index).absoluteFilePath();
    //set the index for the root
    ui->listView->setRootIndex(modelFiles->setRootPath(currentPath));

}

/*Change List Mode*/
void MainWindow::on_actionFileListViewMode_toggled(bool arg1)
{
    if(arg1){
        ui->listView->setViewMode(QListView::IconMode);
        const QSize *gridSize = new QSize(100,100);
        ui->listView->setGridSize(*gridSize);
    }else{
        ui->listView->setViewMode(QListView::ListMode);
        QSize *gridSize = new QSize(ui->listView->width()/3,25);
        ui->listView->setGridSize(*gridSize);
    }
}

/*File Context Menu*/
void MainWindow::showFileContextMenu(const QPoint &pos)
{
    QModelIndexList list =ui->listView->selectionModel()->selectedIndexes();
    int selectedFilesNumber = list.count();

    // Create menu and insert some actions
    QMenu listViewMenu;
    listViewMenu.setStyleSheet("QMenu {background-color: #333; color:#fff;} "
                               "QMenu::item:selected {background-color: #666;}"
                               "QMenu::item:disabled {color: #555;}");
    // Handle global position
    QPoint globalPos = ui->listView->mapToGlobal(pos);


    //Paste action
    QAction *actionPaste = new QAction("Paste");
    connect(actionPaste, SIGNAL(triggered()), this, SLOT(contextMenuFilePaste()));
    actionPaste->setEnabled(false);

    //Rename action
    QAction *actionRename = new QAction("Rename");
    connect(actionRename, SIGNAL(triggered()), this, SLOT(contextMenuFileRename()));
    actionRename->setEnabled(false);

    //Concat action
    QAction *actionConcat = new QAction("Concat");
    connect(actionConcat, SIGNAL(triggered()), this, SLOT(contextMenuFileConcat()));
    actionConcat->setEnabled(false);

    //View action
    QAction *actionView = new QAction("View");
    connect(actionView, SIGNAL(triggered()), this, SLOT(contextMenuFileView()));
    actionView->setVisible(false);

    //show context menu if at least one file is selected
    if(selectedFilesNumber>0){
        listViewMenu.addAction(actionView);
        listViewMenu.addAction(actionConcat);
        listViewMenu.addSeparator();
        listViewMenu.addAction("Cut",  this, SLOT(contextMenuFileCut()));
        listViewMenu.addAction("Copy",  this, SLOT(contextMenuFileCopy()));
        listViewMenu.addAction(actionPaste);
        listViewMenu.addSeparator();
        listViewMenu.addAction("Delete",  this, SLOT(contextMenuFileDelete()));
        listViewMenu.addAction(actionRename);
        listViewMenu.addSeparator();
        listViewMenu.addAction("Properties",  this, SLOT(contextMenuFileProperties()));

        listViewMenu.actions().at(5)->setEnabled(false);

    }else{
        listViewMenu.addAction(actionPaste);
    }

    // enable Paste action if at least one files has been copied to clipboard
    if(clipboardFiles->count()>0){
        actionPaste->setEnabled(true);
    }

    // enable Rename action if only one file has been selected
    if(selectedFilesNumber==1){
        actionRename->setEnabled(true);
    }

    // enable Concat action if multiple text files have been selected
    if(areAllSelectedFilesTxt()){
        if(selectedFilesNumber==1){
            actionView->setVisible(true);
        }

        if(selectedFilesNumber>=2){
            actionConcat->setEnabled(true);
        }
    }

    // Show context menu at handling position
    listViewMenu.exec(globalPos);
}
/*Rename*/
void MainWindow::contextMenuFileRename()
{
    //get file info
    QFileInfo file = modelFiles->fileInfo(ui->listView->selectionModel()->selectedIndexes()[0]);

    //build input dialog
    bool ok;
    QString newFileName = QInputDialog::getText(
                this, tr("Rename"), tr("New file name:"),
                QLineEdit::Normal, file.fileName(), &ok);

    //proceed with renaming
    if (ok && !newFileName.isEmpty()){
        if (QFeXFile::rename(file, newFileName)) {
            ui->listView->repaint();
        }else{
            QMessageBox::warning(
                        0,
                        tr(qPrintable("Error")),
                        tr(qPrintable("There has been an error while trying to rename the file!")));
        }

    }
}

/*View*/
void MainWindow::contextMenuFileView()
{
    setStaturBarWorkingText("Loading file content ...");
    QFileInfo fileInfo = modelFiles->fileInfo(ui->listView->selectionModel()->selectedIndexes()[0]);
    QFile file(fileInfo.absoluteFilePath());
    if (file.open(QFile::ReadOnly | QFile::Text))
    {
        QTextStream in(&file);
        showInLister(in.readAll());
        currentListerFilePath = fileInfo.absoluteFilePath();
    }
    setStaturBarWorkingText("");
}
/*Concat*/
void MainWindow::contextMenuFileConcat()
{

    QString content = "";
    if(ui->listView->selectionModel()->selectedIndexes().count()>0){
        setStaturBarWorkingText("Concatenating files. Please wait ...");




        foreach(QModelIndex index, ui->listView->selectionModel()->selectedIndexes()){
            QFileInfo fileInfo = modelFiles->fileInfo(index);
            QFile file(fileInfo.absoluteFilePath());

            if(currentListerFilePath.isEmpty())
            {
                currentListerFilePath = fileInfo.absoluteFilePath();
            }

            if (!file.open(QFile::ReadOnly | QFile::Text))
                continue;

            QTextStream in(&file);

            content += in.readAll();

        }

        showInLister(content);
        setStaturBarWorkingText("");
    }
}
/*Cut*/
void MainWindow::contextMenuFileCut()
{
    contextMenuFileCopy();
    clipboardFilesRemove = true;

}
/*Copy*/
void MainWindow::contextMenuFileCopy()
{

    clipboardFiles->clear();
    foreach(QModelIndex index, ui->listView->selectionModel()->selectedIndexes()){
        QFileInfo file = modelFiles->fileInfo(index);
        *clipboardFiles << file;
    }
}
/*Paste*/
void MainWindow::contextMenuFilePaste()
{
    if(!clipboardFilesRemove){
        //COPY
        if (QFeXFile::copy(clipboardFiles, currentPath)) {
            ui->listView->repaint();
        }else{
            QMessageBox::warning(
                        0,
                        tr(qPrintable("Error")),
                        tr(qPrintable("There has been an error while trying to copy files to " + currentPath)));
        }
    }else{
        //MOVE
        if (QFeXFile::move(clipboardFiles, currentPath)) {
            ui->listView->repaint();
        }else{
            QMessageBox::warning(
                        0,
                        tr(qPrintable("Error")),
                        tr(qPrintable("There has been an error while trying to move files to " + currentPath)));
        }
    }
    clipboardFilesRemove = false;
}
/*Delete*/
void MainWindow::contextMenuFileDelete()
{
    QList<QFileInfo> *files = new QList<QFileInfo>();
    foreach(QModelIndex index, ui->listView->selectionModel()->selectedIndexes()){
        QFileInfo file = modelFiles->fileInfo(index);
        *files << file;
    }

    if (QFeXFile::remove(files)) {
        ui->listView->repaint();
    }else{
        QMessageBox::warning(
                    0,
                    tr(qPrintable("Error")),
                    tr(qPrintable("There has been an error while trying to delete selected files!")));
    }
}
/*Properties*/
void MainWindow::contextMenuFileProperties()
{
    QList<QFileInfo> *files = new QList<QFileInfo>();
    foreach(QModelIndex index, ui->listView->selectionModel()->selectedIndexes()){
        QFileInfo file = modelFiles->fileInfo(index);
        *files << file;
    }
    FileProperties *fp = new FileProperties(this, files);
    fp->show();
}


bool MainWindow::areAllSelectedFilesTxt()
{
    bool result = true;
    foreach(QModelIndex index, ui->listView->selectionModel()->selectedIndexes()){
        QString extension = modelFiles->fileInfo(index).suffix().toLower();
        if(extension != "txt"){
            result = false;
            break;
        }

    }

    return result;
}

void MainWindow::showInLister(QString text)
{
    if(ui->dockWidgetLister->isHidden())
    {
        ui->dockWidgetLister->show();
    }
    ui->textEdit->clear();
    ui->textEdit->setText(text);
    isListerTextChanged = false;
}

void MainWindow::setStaturBarWorkingText(QString text)
{
    ui->statusBar->showMessage(text);
}

//LISTER CONTEXT MENU
void MainWindow::showExtendedListerContextMenu(const QPoint &pt)
{
    QMenu *menu = ui->textEdit->createStandardContextMenu();
    QTextCursor cursor = ui->textEdit->textCursor();
    menu->setStyleSheet("QMenu {background-color: #333; color:#fff;} "
                        "QMenu::item:selected {background-color: #666;}"
                        "QMenu::item:disabled {color: #555;}");
    //separator
    QAction *separator = new QAction(this);
    separator->setSeparator(true);
    addAction(separator);


    //Save changes action
    QAction *actionSaveChanges = new QAction("Save");
    connect(actionSaveChanges, SIGNAL(triggered()), this, SLOT(listerContextMenuSave()));

    //Save Changes As action
    QAction *actionSaveChangesAs = new QAction("Save as ...");
    connect(actionSaveChangesAs, SIGNAL(triggered()), this, SLOT(listerContextMenuSaveAs()));


    //Save selection action
    QAction *actionSaveSelection = new QAction("Save selection as ...");
    connect(actionSaveSelection, SIGNAL(triggered()), this, SLOT(listerContextMenuSaveSelection()));

    if(isListerTextChanged){
        menu->insertAction(menu->actions()[0],actionSaveChanges);
        menu->insertAction(menu->actions()[1],actionSaveChangesAs);
        menu->insertAction(menu->actions()[2],separator);
    }

    if(cursor.selectedText()!=""){
        menu->insertAction(menu->actions()[0],actionSaveSelection);
        menu->insertAction(menu->actions()[1],separator);
    }

    menu->exec(ui->textEdit->mapToGlobal(pt));
    delete menu;

}

void MainWindow::enableExtendedListerContextMenuSaveAction()
{
    isListerTextChanged = true;
}

/*Lister Save*/
void MainWindow::listerContextMenuSave()
{
    if (!currentListerFilePath.isEmpty()){
        if (QFeXFile::saveContent(ui->textEdit->toPlainText(), currentListerFilePath)) {
            setStaturBarWorkingText("File saved.");
        }else{
            QMessageBox::warning(
                        0,
                        tr(qPrintable("Error")),
                        tr(qPrintable("There has been an error while trying to save this file!")));
        }

    }
}
/*Lister Save As*/
void MainWindow::listerContextMenuSaveAs()
{
    //get file info
    QFileInfo *file = new QFileInfo(currentListerFilePath);

    //build input dialog
    bool ok;
    QString newFileName = QInputDialog::getText(
                this, tr("Save as ..."), tr("New file name:"),
                QLineEdit::Normal, file->fileName(), &ok);

    //proceed with saving
    if (!currentListerFilePath.isEmpty()){
        if (QFeXFile::saveContent(ui->textEdit->toPlainText(), file->absolutePath() + newFileName)) {
            setStaturBarWorkingText("File saved.");
        }else{
            QMessageBox::warning(
                        0,
                        tr(qPrintable("Error")),
                        tr(qPrintable("There has been an error while trying to save this file!")));
        }

    }
}

/*Lister Save Selection As*/
void MainWindow::listerContextMenuSaveSelection()
{
    //build input dialog
    bool ok;
    QString newFileName = QInputDialog::getText(
                this, tr("Save selection"), tr("File name:"),
                QLineEdit::Normal, "", &ok);

    //proceed with saving
    if (!currentListerFilePath.isEmpty()){
        if (QFeXFile::saveContent(ui->textEdit->textCursor().selectedText(), currentPath + newFileName)) {
            setStaturBarWorkingText("Selection saved.");
        }else{
            QMessageBox::warning(
                        0,
                        tr(qPrintable("Error")),
                        tr(qPrintable("There has been an error while trying to save this file!")));
        }

    }
}

//open or execute files
void MainWindow::itemDoubleClicked(QModelIndex index) {
    QFileInfo file = modelFiles->fileInfo(index);

    if(file.isDir()){
        on_treeView_clicked(index);
        ui->treeView->expand(modelDirectories->index(file.absolutePath()));
        ui->treeView->repaint();
    }else{
        if(file.suffix() =="exe"){
            QProcess *process = new QProcess(this);
            QStringList arguments;
            arguments << "";
            process->start(file.absoluteFilePath(),arguments);
        }else{
            QDesktopServices::openUrl(QUrl(file.absoluteFilePath(), QUrl::TolerantMode));
        }
    }
}

void MainWindow::on_actionExit_triggered()
{
    this->close();
}
