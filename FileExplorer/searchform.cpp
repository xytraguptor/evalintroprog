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

    ui->dockWidget->hide();

SearchForm::enableButtons(false);
}

SearchForm::~SearchForm()
{
    delete ui;
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
}
