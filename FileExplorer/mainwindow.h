#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QPushButton"
#include "QIcon"
#include "QFileSystemModel"
#include "QTreeWidgetItem"
#include "aboutform.h"
#include "QFileSystemModel"
#include "searchform.h"
#include "fileproperties.h"
#include "QTextStream"
#include "QDesktopServices"
#include "QProcess"

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
    bool clipboardFilesRemove;
    bool areAllSelectedFilesTxt();
    void showInLister(QString);
    void setStatusBarWorkingText(QString);
    QMenu *listerContextMenu;
    bool isListerTextChanged;
    QString currentListerFilePath;
    QLineEdit *addressBar;


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
    void contextMenuFileView();
    void showExtendedListerContextMenu(const QPoint &pt);
    void enableExtendedListerContextMenuSaveAction();
    void listerContextMenuSave();
    void listerContextMenuSaveAs();
    void listerContextMenuSaveSelection();
    void itemDoubleClicked(QModelIndex index);
    void on_actionExit_triggered();
    void on_modelDirectories_rootPathChanged(QString);
    void on_addressBar_returnPressed();
};

#endif // MAINWINDOW_H
