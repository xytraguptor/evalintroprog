#include "QFileSystemModel"
#include "searchform.h"
#include "ui_searchform.h"


SearchForm::SearchForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SearchForm)
{
    ui->setupUi(this);
    this->
    //  penStyleComboBox = new QComboBox;
    ui->cbDepth->addItem(tr("all (unlimited depth)"), -1);
    ui->cbDepth->addItem(tr("current dir only"), 0);
    ui->cbDepth->addItem(tr("1 level"), 1);
    ui->cbDepth->addItem(tr("2 levels"), 2);
    ui->cbDepth->addItem(tr("3 levels"), 3);
    ui->cbDepth->addItem(tr("4 levels"), 4);
    ui->cbDepth->addItem(tr("5 levels"), 5);
    ui->cbDepth->addItem(tr("6 levels"), 6);
    ui->cbDepth->addItem(tr("7 levels"), 7);
    ui->cbDepth->addItem(tr("8 levels"), 8);


    //resize search window
    resize(parent->width()/2, parent->height()/2);
    //move the window to center of the parent
    const QPoint global = mapToGlobal(parent->rect().center());
    move(global.x() - width() / 2, global.y() - height() / 2);

    ui->dockWidget->hide();

    listViewModel = new QStringListModel();

    SearchForm::enableButtons(false);


}

SearchForm::~SearchForm()
{
    delete ui;
}
void SearchForm::setCurrentPath(QString path)
{
    ui->txtSearchIn->setText(path);
}
void SearchForm::enableButtons(bool enable){
    ui->btnEdit->setEnabled(enable);
    ui->btnView->setEnabled(enable);
    ui->btnGoToFile->setEnabled(enable);
}

void SearchForm::on_btnCancel_pressed()
{
    this->close();
}

void SearchForm::on_btnStartSearch_released()
{
    ui->dockWidget->show();
    setStatusBarWorkingText("Searching for files ...");
    ui->dockWidget->repaint();

    QString searchQuery = ui->txtSearchFor->text();
    QString searchPath = ui->txtSearchIn->text();
    QString searchText = ui->txtFindText->text();
    int dirDepth = ui->cbDepth->currentData().toInt();
    bool isCaseSensitive = ui->chkCaseSensitive->checkState();
    bool showLineNumbers = ui->chkCaseSensitive->checkState();
    bool showFilePath = ui->chkCaseSensitive->checkState();


    //QFeXSearch *search = new QFeXSearch;
    QFeXSearch *search = new QFeXSearch(searchQuery, searchPath, dirDepth,searchText,isCaseSensitive,showLineNumbers,showFilePath);
    QStringList result = search->getFilteredFiles();
    listViewModel->setStringList(result);

//resize list view and set the model
    int height = result.count() *17;
    if(height>300)
        height = 300;
    ui->listView->setMinimumHeight(height);
    ui->listView->setModel(listViewModel);

    setStatusBarWorkingText(QString::number(result.count()) + " files found!");
}

void SearchForm::setStatusBarWorkingText(QString text)
{
    ui->lblStatusBar->setText(text);
}
