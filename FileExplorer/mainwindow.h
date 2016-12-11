#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "aboutform.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

public slots:

private slots:
    void on_action_Search_triggered();
    void on_actionAbout_triggered();
    void on_actionShow_Treeview_toggled(bool arg1);
    void on_actionLister_toggled(bool arg1);
    void on_dockWidgetLister_visibilityChanged(bool visible);
};

#endif // MAINWINDOW_H
