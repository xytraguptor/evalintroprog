/********************************************************************************
** Form generated from reading UI file 'searchform.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHFORM_H
#define UI_SEARCHFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SearchForm
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QGridLayout *gridLayout_4;
    QLabel *label;
    QLineEdit *txtSearchIn;
    QFrame *line;
    QLabel *label_5;
    QLineEdit *txtSearchFor;
    QLabel *label_2;
    QLineEdit *txtFindText;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QComboBox *cbDepth;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *chkCaseSensitive;
    QCheckBox *chkShowLineNumber;
    QHBoxLayout *horizontalLayout;
    QCheckBox *chkShowOnlyFiles;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *btnStartSearch;
    QPushButton *btnCancel;
    QDockWidget *dockWidget;
    QWidget *dockWidgetContents_2;
    QVBoxLayout *verticalLayout_3;
    QListView *listView;
    QWidget *buttonBar_2;
    QHBoxLayout *buttonBar;
    QPushButton *btnView;
    QPushButton *btnEdit;
    QPushButton *btnGoToFile;

    void setupUi(QDialog *SearchForm)
    {
        if (SearchForm->objectName().isEmpty())
            SearchForm->setObjectName(QStringLiteral("SearchForm"));
        SearchForm->resize(601, 681);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SearchForm->sizePolicy().hasHeightForWidth());
        SearchForm->setSizePolicy(sizePolicy);
        SearchForm->setMinimumSize(QSize(600, 0));
        SearchForm->setContextMenuPolicy(Qt::PreventContextMenu);
        SearchForm->setStyleSheet(QStringLiteral("background-color: rgba(253, 253, 253, 253);"));
        SearchForm->setModal(true);
        verticalLayout_2 = new QVBoxLayout(SearchForm);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetMinAndMaxSize);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setSizeConstraint(QLayout::SetFixedSize);
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_4->setSizeConstraint(QLayout::SetFixedSize);
        label = new QLabel(SearchForm);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_4->addWidget(label, 0, 0, 1, 1);

        txtSearchIn = new QLineEdit(SearchForm);
        txtSearchIn->setObjectName(QStringLiteral("txtSearchIn"));

        gridLayout_4->addWidget(txtSearchIn, 1, 1, 1, 1);

        line = new QFrame(SearchForm);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_4->addWidget(line, 3, 1, 1, 1);

        label_5 = new QLabel(SearchForm);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout_4->addWidget(label_5, 4, 0, 1, 1);

        txtSearchFor = new QLineEdit(SearchForm);
        txtSearchFor->setObjectName(QStringLiteral("txtSearchFor"));

        gridLayout_4->addWidget(txtSearchFor, 0, 1, 1, 1);

        label_2 = new QLabel(SearchForm);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_4->addWidget(label_2, 1, 0, 1, 1);

        txtFindText = new QLineEdit(SearchForm);
        txtFindText->setObjectName(QStringLiteral("txtFindText"));

        gridLayout_4->addWidget(txtFindText, 4, 1, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_3 = new QLabel(SearchForm);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 0, 0, 1, 1);

        cbDepth = new QComboBox(SearchForm);
        cbDepth->setObjectName(QStringLiteral("cbDepth"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(cbDepth->sizePolicy().hasHeightForWidth());
        cbDepth->setSizePolicy(sizePolicy1);
        cbDepth->setMinimumSize(QSize(0, 24));
        cbDepth->setContextMenuPolicy(Qt::PreventContextMenu);
        cbDepth->setAutoFillBackground(false);
        cbDepth->setStyleSheet(QStringLiteral("border-color: rgb(85, 170, 255);"));
        cbDepth->setEditable(false);
        cbDepth->setFrame(true);

        gridLayout->addWidget(cbDepth, 0, 1, 1, 1);


        gridLayout_4->addLayout(gridLayout, 2, 1, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        chkCaseSensitive = new QCheckBox(SearchForm);
        chkCaseSensitive->setObjectName(QStringLiteral("chkCaseSensitive"));

        horizontalLayout_2->addWidget(chkCaseSensitive);

        chkShowLineNumber = new QCheckBox(SearchForm);
        chkShowLineNumber->setObjectName(QStringLiteral("chkShowLineNumber"));
        chkShowLineNumber->setChecked(true);

        horizontalLayout_2->addWidget(chkShowLineNumber);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        chkShowOnlyFiles = new QCheckBox(SearchForm);
        chkShowOnlyFiles->setObjectName(QStringLiteral("chkShowOnlyFiles"));
        chkShowOnlyFiles->setChecked(true);

        horizontalLayout->addWidget(chkShowOnlyFiles);


        horizontalLayout_2->addLayout(horizontalLayout);


        gridLayout_4->addLayout(horizontalLayout_2, 5, 1, 1, 1);


        horizontalLayout_4->addLayout(gridLayout_4);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        btnStartSearch = new QPushButton(SearchForm);
        btnStartSearch->setObjectName(QStringLiteral("btnStartSearch"));
        btnStartSearch->setStyleSheet(QLatin1String("border-color: rgb(0, 170, 255);\n"
"border-bottom-color: rgb(255, 85, 0);\n"
""));
        btnStartSearch->setAutoRepeat(false);
        btnStartSearch->setFlat(true);

        horizontalLayout_3->addWidget(btnStartSearch);

        btnCancel = new QPushButton(SearchForm);
        btnCancel->setObjectName(QStringLiteral("btnCancel"));
        btnCancel->setAutoFillBackground(false);
        btnCancel->setStyleSheet(QLatin1String("border-color: rgb(0, 170, 255);\n"
"gridline-color: rgb(255, 255, 127);"));
        btnCancel->setAutoDefault(false);
        btnCancel->setFlat(true);

        horizontalLayout_3->addWidget(btnCancel);


        verticalLayout_2->addLayout(horizontalLayout_3);

        dockWidget = new QDockWidget(SearchForm);
        dockWidget->setObjectName(QStringLiteral("dockWidget"));
        dockWidget->setFeatures(QDockWidget::DockWidgetClosable);
        dockWidget->setAllowedAreas(Qt::BottomDockWidgetArea);
        dockWidgetContents_2 = new QWidget();
        dockWidgetContents_2->setObjectName(QStringLiteral("dockWidgetContents_2"));
        verticalLayout_3 = new QVBoxLayout(dockWidgetContents_2);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        listView = new QListView(dockWidgetContents_2);
        listView->setObjectName(QStringLiteral("listView"));
        listView->setFrameShape(QFrame::NoFrame);
        listView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        listView->setEditTriggers(QAbstractItemView::DoubleClicked);

        verticalLayout_3->addWidget(listView);

        buttonBar_2 = new QWidget(dockWidgetContents_2);
        buttonBar_2->setObjectName(QStringLiteral("buttonBar_2"));
        buttonBar = new QHBoxLayout(buttonBar_2);
        buttonBar->setObjectName(QStringLiteral("buttonBar"));
        btnView = new QPushButton(buttonBar_2);
        btnView->setObjectName(QStringLiteral("btnView"));

        buttonBar->addWidget(btnView);

        btnEdit = new QPushButton(buttonBar_2);
        btnEdit->setObjectName(QStringLiteral("btnEdit"));

        buttonBar->addWidget(btnEdit);

        btnGoToFile = new QPushButton(buttonBar_2);
        btnGoToFile->setObjectName(QStringLiteral("btnGoToFile"));

        buttonBar->addWidget(btnGoToFile);


        verticalLayout_3->addWidget(buttonBar_2);

        dockWidget->setWidget(dockWidgetContents_2);

        verticalLayout_2->addWidget(dockWidget);


        retranslateUi(SearchForm);

        btnStartSearch->setDefault(true);
        btnCancel->setDefault(false);


        QMetaObject::connectSlotsByName(SearchForm);
    } // setupUi

    void retranslateUi(QDialog *SearchForm)
    {
        SearchForm->setWindowTitle(QApplication::translate("SearchForm", "Find Files ...", Q_NULLPTR));
        label->setText(QApplication::translate("SearchForm", "Search for:", Q_NULLPTR));
        label_5->setText(QApplication::translate("SearchForm", "Find text:", Q_NULLPTR));
        txtSearchFor->setText(QString());
        txtSearchFor->setPlaceholderText(QApplication::translate("SearchForm", "*.*", Q_NULLPTR));
        label_2->setText(QApplication::translate("SearchForm", "Search in:", Q_NULLPTR));
        label_3->setText(QApplication::translate("SearchForm", "Search in subdirectories:", Q_NULLPTR));
        chkCaseSensitive->setText(QApplication::translate("SearchForm", "Case sensitive", Q_NULLPTR));
        chkShowLineNumber->setText(QApplication::translate("SearchForm", "Show line number", Q_NULLPTR));
        chkShowOnlyFiles->setText(QApplication::translate("SearchForm", "Show only file path", Q_NULLPTR));
        btnStartSearch->setText(QApplication::translate("SearchForm", "Search", Q_NULLPTR));
        btnCancel->setText(QApplication::translate("SearchForm", "Cancel", Q_NULLPTR));
        btnView->setText(QApplication::translate("SearchForm", "View", Q_NULLPTR));
        btnEdit->setText(QApplication::translate("SearchForm", "Edit", Q_NULLPTR));
        btnGoToFile->setText(QApplication::translate("SearchForm", "Go to file", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SearchForm: public Ui_SearchForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHFORM_H
