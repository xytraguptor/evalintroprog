#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "aboutform.h"
#include "QFileSystemModel"
#include "searchform.h"
#include "fileproperties.h"

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
    QFileSystemModel *modelDirectories;
    QFileSystemModel *modelFiles;
    QString currentPath;
    QList<QFileInfo> *clipboardFiles;

public slots:

private slots:
    void on_action_Search_triggered();
    void on_actionAbout_triggered();
    void on_actionShow_Treeview_toggled(bool arg1);
    void on_actionLister_toggled(bool arg1);
    void on_dockWidgetLister_visibilityChanged(bool visible);
    void on_treeView_clicked(const QModelIndex &index);
    void on_actionFileListViewMode_toggled(bool arg1);
    void showFileContextMenu(const QPoint&);
    void contextMenuFileRename();
    void contextMenuFileConcat();
    void contextMenuFileCut();
    void contextMenuFileCopy();
    void contextMenuFilePaste();
    void contextMenuFileDelete();
    void contextMenuFileProperties();
};

#endif // MAINWINDOW_H
