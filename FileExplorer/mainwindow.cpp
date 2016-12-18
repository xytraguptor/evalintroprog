#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "aboutform.h"
#include "qfexpath.h"
#include "QPushButton"
#include "QIcon"
#include "QFileSystemModel"
#include "QTreeWidgetItem"
#include "searchform.h"
#include "fileproperties.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);




    //QMainWindow::centralWidget()->layout()->setContentsMargins(0, 0, 0, 0);
    this->layout()->setContentsMargins(0, 0, 0, 0);

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
    modelFiles->setFilter(QDir::NoDotAndDotDot | QDir::Files | QDir::Hidden); //filter files only and hide ".." folders
    ui->listView->setModel(modelFiles);


//    QFrame *status_frame = new QFrame();
//        status_frame->setFrameStyle(QFrame::Panel | QFrame::Sunken);

//        QHBoxLayout *layout = new QHBoxLayout(status_frame);
//        layout->setContentsMargins(0, 0, 0, 0);
////        QProgressBar *bar = new QProgressBar(status_frame);
////        bar->setMaximumHeight(10);
////        bar->setMaximumWidth(100);


//        QPushButton *box = new QPushButton(tr(""), status_frame);

//        box->setIcon(QIcon(":Resources/magnifier16.png"));
//        box->setCheckable(true);

//        //layout->addWidget(bar);
//        layout->addWidget(box);
//        ui->statusBar->insertPermanentWidget(5, status_frame);


    //set context menu
    ui->listView->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->listView, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(showFileContextMenu(QPoint)));


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
    }else{
        ui->listView->setViewMode(QListView::ListMode);
    }
}

/*File Context Menu*/
void MainWindow::showFileContextMenu(const QPoint &pos)
{
     QModelIndexList list =ui->listView->selectionModel()->selectedIndexes();

     //show context menu if at least one file is selected
     if(list.count()>0){
         // Handle global position
         QPoint globalPos = ui->listView->mapToGlobal(pos);

         // Create menu and insert some actions
         QMenu myMenu;


         myMenu.addAction("Concat",  this, SLOT(contextMenuFileConcat()));
         myMenu.addSeparator();
         myMenu.addAction("Cut",  this, SLOT(contextMenuFileCut()));
         myMenu.addAction("Copy",  this, SLOT(contextMenuFileCopy()));
         myMenu.addAction("Paste",  this, SLOT(contextMenuFilePaste()));
         myMenu.addSeparator();
         myMenu.addAction("Delete",  this, SLOT(contextMenuFileDelete()));
         myMenu.addAction("Rename",  this, SLOT(contextMenuFileRename()));
         myMenu.addSeparator();
         myMenu.addAction("Properties",  this, SLOT(contextMenuFileProperties()));

         // Show context menu at handling position
         myMenu.exec(globalPos);
     }
}
/*Rename*/
void MainWindow::contextMenuFileRename()
 {

 }
/*Concat*/
void MainWindow::contextMenuFileConcat()
 {

 }
/*Cut*/
void MainWindow::contextMenuFileCut()
 {

 }
/*Copy*/
void MainWindow::contextMenuFileCopy()
{

}
/*Paste*/
void MainWindow::contextMenuFilePaste()
 {

 }
/*Delete*/
void MainWindow::contextMenuFileDelete()
 {

 }
/*Properties*/
void MainWindow::contextMenuFileProperties()
 {
    //int size =0;
    QList<QFileInfo> *files = new QList<QFileInfo>();
    foreach(QModelIndex index, ui->listView->selectionModel()->selectedIndexes()){
       QFileInfo file = modelFiles->fileInfo(index);
       //size +=file.size();
       *files << file;
    }
    FileProperties *fp = new FileProperties(this, files);
    fp->show();
 }
