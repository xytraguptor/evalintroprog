#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "aboutform.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_action_Search_triggered()
{

}

void MainWindow::on_actionAbout_triggered()
{
    AboutForm *ab = new AboutForm(this);
    ab->show();
}
