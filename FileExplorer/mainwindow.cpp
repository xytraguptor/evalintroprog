#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "aboutform.h"
#include "QPushButton"
#include "QIcon"
#include "QPropertyAnimation"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //QMainWindow::centralWidget()->layout()->setContentsMargins(0, 0, 0, 0);
    this->layout()->setContentsMargins(0, 0, 0, 0);

/* set up dock widget object */
    QWidget* titleWidget = new QWidget(this);
    ui->dockWidget->setTitleBarWidget( titleWidget );
    ui->dockWidgetLister->setContentsMargins(0, 0, 0, 0);


    QFrame *status_frame = new QFrame();
        status_frame->setFrameStyle(QFrame::Panel | QFrame::Sunken);

        QHBoxLayout *layout = new QHBoxLayout(status_frame);
        layout->setContentsMargins(0, 0, 0, 0);
//        QProgressBar *bar = new QProgressBar(status_frame);
//        bar->setMaximumHeight(10);
//        bar->setMaximumWidth(100);


        QPushButton *box = new QPushButton(tr(""), status_frame);

        box->setIcon(QIcon(":Resources/magnifier16.png"));
        box->setCheckable(true);

        //layout->addWidget(bar);
        layout->addWidget(box);
        ui->statusBar->insertPermanentWidget(5, status_frame);


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
