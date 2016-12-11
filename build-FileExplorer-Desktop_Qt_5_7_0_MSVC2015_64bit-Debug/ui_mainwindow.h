/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_Search;
    QAction *actionAbout;
    QAction *actionLister;
    QAction *actionShow_Treeview;
    QAction *actionFileListViewMode;
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QListView *listView;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuHelp;
    QMenu *menuEdit;
    QMenu *menuView;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QDockWidget *dockWidget;
    QWidget *dockWidgetContents;
    QGridLayout *gridLayout;
    QTreeView *treeView;
    QDockWidget *dockWidgetLister;
    QWidget *dockWidgetContents_12;
    QGridLayout *gridLayout_3;
    QTextEdit *textEdit;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(755, 495);
        QIcon icon;
        icon.addFile(QStringLiteral(":/ico/Resources/note-240.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setAutoFillBackground(false);
        MainWindow->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        action_Search = new QAction(MainWindow);
        action_Search->setObjectName(QStringLiteral("action_Search"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/ico/Resources/wmagnifier16.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Search->setIcon(icon1);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionLister = new QAction(MainWindow);
        actionLister->setObjectName(QStringLiteral("actionLister"));
        actionLister->setCheckable(true);
        actionLister->setChecked(true);
        actionShow_Treeview = new QAction(MainWindow);
        actionShow_Treeview->setObjectName(QStringLiteral("actionShow_Treeview"));
        actionShow_Treeview->setCheckable(true);
        actionShow_Treeview->setChecked(true);
        actionFileListViewMode = new QAction(MainWindow);
        actionFileListViewMode->setObjectName(QStringLiteral("actionFileListViewMode"));
        actionFileListViewMode->setCheckable(true);
        actionFileListViewMode->setChecked(true);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/ico/Resources/wlistp-16.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon2.addFile(QStringLiteral(":/ico/Resources/listp-16.png"), QSize(), QIcon::Active, QIcon::Off);
        icon2.addFile(QStringLiteral(":/ico/Resources/wlist-16.png"), QSize(), QIcon::Active, QIcon::On);
        icon2.addFile(QStringLiteral("Resources/wlistp-16.png"), QSize(), QIcon::Selected, QIcon::On);
        actionFileListViewMode->setIcon(icon2);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        listView = new QListView(centralWidget);
        listView->setObjectName(QStringLiteral("listView"));
        listView->setFrameShape(QFrame::NoFrame);
        listView->setFrameShadow(QFrame::Plain);
        listView->setSelectionMode(QAbstractItemView::ExtendedSelection);
        listView->setTextElideMode(Qt::ElideNone);
        listView->setProperty("isWrapping", QVariant(false));
        listView->setResizeMode(QListView::Adjust);
        listView->setLayoutMode(QListView::SinglePass);
        listView->setSpacing(5);
        listView->setViewMode(QListView::IconMode);
        listView->setUniformItemSizes(true);
        listView->setWordWrap(true);

        gridLayout_2->addWidget(listView, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 755, 21));
        menuBar->setContextMenuPolicy(Qt::PreventContextMenu);
        menuBar->setAutoFillBackground(false);
        menuBar->setStyleSheet(QLatin1String("background-color: rgb(51, 51, 51);\n"
"color: rgb(234, 234, 234);"));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuView = new QMenu(menuBar);
        menuView->setObjectName(QStringLiteral("menuView"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mainToolBar->setContextMenuPolicy(Qt::PreventContextMenu);
        mainToolBar->setLayoutDirection(Qt::RightToLeft);
        mainToolBar->setAutoFillBackground(false);
        mainToolBar->setStyleSheet(QLatin1String("background-color: rgb(51, 51, 51);\n"
"border-bottom-color: rgb(0, 0, 0);\n"
"border-color: rgb(0, 170, 255);\n"
"color: rgb(238, 238, 238);"));
        mainToolBar->setMovable(false);
        mainToolBar->setToolButtonStyle(Qt::ToolButtonFollowStyle);
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        dockWidget = new QDockWidget(MainWindow);
        dockWidget->setObjectName(QStringLiteral("dockWidget"));
        dockWidget->setMinimumSize(QSize(250, 131));
        dockWidget->setAutoFillBackground(false);
        dockWidget->setStyleSheet(QStringLiteral("background-color: rgb(51, 51, 51);"));
        dockWidget->setFloating(false);
        dockWidget->setFeatures(QDockWidget::DockWidgetClosable|QDockWidget::DockWidgetVerticalTitleBar);
        dockWidget->setAllowedAreas(Qt::LeftDockWidgetArea|Qt::RightDockWidgetArea);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QStringLiteral("dockWidgetContents"));
        gridLayout = new QGridLayout(dockWidgetContents);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        treeView = new QTreeView(dockWidgetContents);
        treeView->setObjectName(QStringLiteral("treeView"));
        treeView->setFocusPolicy(Qt::TabFocus);
#ifndef QT_NO_TOOLTIP
        treeView->setToolTip(QStringLiteral(""));
#endif // QT_NO_TOOLTIP
        treeView->setAutoFillBackground(true);
        treeView->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"selection-background-color: transparent;\n"
"selection-color: transparent;\n"
"\n"
"\n"
"\n"
"QTreeView::branch:open:has-children:!has-siblings,\n"
"QTreeView::branch:open:has-children:has-siblings {\n"
"border-image: none;\n"
"image: url(:/ico/Resources/magnifier16.png);\n"
"}"));
        treeView->setFrameShape(QFrame::NoFrame);
        treeView->setFrameShadow(QFrame::Plain);
        treeView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        treeView->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        treeView->setAutoScrollMargin(10);
        treeView->setTabKeyNavigation(true);
        treeView->setTextElideMode(Qt::ElideLeft);
        treeView->setIndentation(10);
        treeView->setRootIsDecorated(true);
        treeView->setItemsExpandable(true);
        treeView->setAnimated(true);
        treeView->setHeaderHidden(true);
        treeView->header()->setVisible(false);

        gridLayout->addWidget(treeView, 0, 0, 1, 1);

        dockWidget->setWidget(dockWidgetContents);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dockWidget);
        dockWidgetLister = new QDockWidget(MainWindow);
        dockWidgetLister->setObjectName(QStringLiteral("dockWidgetLister"));
        dockWidgetLister->setEnabled(true);
        dockWidgetLister->setMinimumSize(QSize(89, 200));
        dockWidgetLister->setAutoFillBackground(false);
        dockWidgetLister->setStyleSheet(QLatin1String("\n"
"border-bottom-color: rgb(85, 255, 127);\n"
"border-top-color: rgb(0, 85, 255);\n"
"gridline-color: rgb(255, 170, 255);\n"
"border-top-color: rgb(255, 170, 127);\n"
"alternate-background-color: rgb(255, 255, 127);"));
        dockWidgetLister->setFeatures(QDockWidget::DockWidgetClosable);
        dockWidgetLister->setAllowedAreas(Qt::BottomDockWidgetArea);
        dockWidgetContents_12 = new QWidget();
        dockWidgetContents_12->setObjectName(QStringLiteral("dockWidgetContents_12"));
        gridLayout_3 = new QGridLayout(dockWidgetContents_12);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        textEdit = new QTextEdit(dockWidgetContents_12);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setFrameShape(QFrame::NoFrame);
        textEdit->setFrameShadow(QFrame::Plain);

        gridLayout_3->addWidget(textEdit, 0, 0, 1, 1);

        dockWidgetLister->setWidget(dockWidgetContents_12);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(8), dockWidgetLister);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuView->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuHelp->addAction(actionAbout);
        menuView->addAction(actionShow_Treeview);
        menuView->addAction(actionLister);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionFileListViewMode);
        mainToolBar->addAction(action_Search);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "QFeX", 0));
        action_Search->setText(QApplication::translate("MainWindow", "&Search", 0));
#ifndef QT_NO_TOOLTIP
        action_Search->setToolTip(QApplication::translate("MainWindow", "Search documents and folders", 0));
#endif // QT_NO_TOOLTIP
        action_Search->setShortcut(QApplication::translate("MainWindow", "Alt+S", 0));
        actionAbout->setText(QApplication::translate("MainWindow", "About", 0));
#ifndef QT_NO_TOOLTIP
        actionAbout->setToolTip(QApplication::translate("MainWindow", "About QFeX", 0));
#endif // QT_NO_TOOLTIP
        actionLister->setText(QApplication::translate("MainWindow", "Show Lister", 0));
#ifndef QT_NO_TOOLTIP
        actionLister->setToolTip(QApplication::translate("MainWindow", "Show Lister window", 0));
#endif // QT_NO_TOOLTIP
        actionShow_Treeview->setText(QApplication::translate("MainWindow", "Treeview", 0));
#ifndef QT_NO_TOOLTIP
        actionShow_Treeview->setToolTip(QApplication::translate("MainWindow", "Show Treeview", 0));
#endif // QT_NO_TOOLTIP
        actionFileListViewMode->setText(QApplication::translate("MainWindow", "File List view mode", 0));
#ifndef QT_NO_TOOLTIP
        actionFileListViewMode->setToolTip(QApplication::translate("MainWindow", "Switch between Details/Icon modes", 0));
#endif // QT_NO_TOOLTIP
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", 0));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", 0));
        menuView->setTitle(QApplication::translate("MainWindow", "View", 0));
        dockWidgetLister->setWindowTitle(QApplication::translate("MainWindow", "Lister", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
