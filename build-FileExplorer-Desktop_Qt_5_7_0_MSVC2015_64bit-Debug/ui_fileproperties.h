/********************************************************************************
** Form generated from reading UI file 'fileproperties.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILEPROPERTIES_H
#define UI_FILEPROPERTIES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FileProperties
{
public:
    QGridLayout *gridLayout;
    QDialogButtonBox *buttonBox;
    QTabWidget *tabWidget;
    QWidget *tabGeneral;
    QGridLayout *gridLayout_2;
    QFormLayout *formLayout;
    QLabel *lblFileIcon;
    QLabel *lblFileInfo;
    QFrame *line;
    QLabel *label_2;
    QLabel *lblFileType;
    QLabel *label_4;
    QLabel *lblFileLocation;
    QLabel *label_6;
    QLabel *lblFileSize;
    QFrame *line_2;
    QLabel *lblFileCreated2;
    QLabel *lblFileCreated;
    QLabel *lblFileModified2;
    QLabel *lblFileModified;
    QLabel *lblFileAccessed2;
    QLabel *lblFileAccessed;
    QWidget *tabDetails;
    QGridLayout *gridLayout_3;
    QFormLayout *formLayout_2;
    QLabel *label_5;
    QFormLayout *formLayout_3;
    QLabel *label;
    QLabel *lblAttrRead;
    QLabel *label_13;
    QLabel *lblAttrWrite;
    QLabel *label_14;
    QLabel *lblAttrExe;

    void setupUi(QDialog *FileProperties)
    {
        if (FileProperties->objectName().isEmpty())
            FileProperties->setObjectName(QStringLiteral("FileProperties"));
        FileProperties->resize(349, 434);
        gridLayout = new QGridLayout(FileProperties);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        buttonBox = new QDialogButtonBox(FileProperties);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(true);

        gridLayout->addWidget(buttonBox, 1, 0, 1, 1);

        tabWidget = new QTabWidget(FileProperties);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setAutoFillBackground(true);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabGeneral = new QWidget();
        tabGeneral->setObjectName(QStringLiteral("tabGeneral"));
        gridLayout_2 = new QGridLayout(tabGeneral);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        lblFileIcon = new QLabel(tabGeneral);
        lblFileIcon->setObjectName(QStringLiteral("lblFileIcon"));
        lblFileIcon->setMinimumSize(QSize(24, 24));

        formLayout->setWidget(0, QFormLayout::LabelRole, lblFileIcon);

        lblFileInfo = new QLabel(tabGeneral);
        lblFileInfo->setObjectName(QStringLiteral("lblFileInfo"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        lblFileInfo->setFont(font);

        formLayout->setWidget(0, QFormLayout::FieldRole, lblFileInfo);

        line = new QFrame(tabGeneral);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        formLayout->setWidget(1, QFormLayout::FieldRole, line);

        label_2 = new QLabel(tabGeneral);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_2);

        lblFileType = new QLabel(tabGeneral);
        lblFileType->setObjectName(QStringLiteral("lblFileType"));

        formLayout->setWidget(2, QFormLayout::FieldRole, lblFileType);

        label_4 = new QLabel(tabGeneral);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        lblFileLocation = new QLabel(tabGeneral);
        lblFileLocation->setObjectName(QStringLiteral("lblFileLocation"));
        QFont font1;
        font1.setBold(false);
        font1.setWeight(50);
        lblFileLocation->setFont(font1);

        formLayout->setWidget(3, QFormLayout::FieldRole, lblFileLocation);

        label_6 = new QLabel(tabGeneral);
        label_6->setObjectName(QStringLiteral("label_6"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_6);

        lblFileSize = new QLabel(tabGeneral);
        lblFileSize->setObjectName(QStringLiteral("lblFileSize"));

        formLayout->setWidget(4, QFormLayout::FieldRole, lblFileSize);

        line_2 = new QFrame(tabGeneral);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        formLayout->setWidget(5, QFormLayout::FieldRole, line_2);

        lblFileCreated2 = new QLabel(tabGeneral);
        lblFileCreated2->setObjectName(QStringLiteral("lblFileCreated2"));

        formLayout->setWidget(6, QFormLayout::LabelRole, lblFileCreated2);

        lblFileCreated = new QLabel(tabGeneral);
        lblFileCreated->setObjectName(QStringLiteral("lblFileCreated"));

        formLayout->setWidget(6, QFormLayout::FieldRole, lblFileCreated);

        lblFileModified2 = new QLabel(tabGeneral);
        lblFileModified2->setObjectName(QStringLiteral("lblFileModified2"));

        formLayout->setWidget(7, QFormLayout::LabelRole, lblFileModified2);

        lblFileModified = new QLabel(tabGeneral);
        lblFileModified->setObjectName(QStringLiteral("lblFileModified"));

        formLayout->setWidget(7, QFormLayout::FieldRole, lblFileModified);

        lblFileAccessed2 = new QLabel(tabGeneral);
        lblFileAccessed2->setObjectName(QStringLiteral("lblFileAccessed2"));

        formLayout->setWidget(8, QFormLayout::LabelRole, lblFileAccessed2);

        lblFileAccessed = new QLabel(tabGeneral);
        lblFileAccessed->setObjectName(QStringLiteral("lblFileAccessed"));

        formLayout->setWidget(8, QFormLayout::FieldRole, lblFileAccessed);


        gridLayout_2->addLayout(formLayout, 0, 0, 1, 1);

        tabWidget->addTab(tabGeneral, QString());
        lblFileIcon->raise();
        tabDetails = new QWidget();
        tabDetails->setObjectName(QStringLiteral("tabDetails"));
        gridLayout_3 = new QGridLayout(tabDetails);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        label_5 = new QLabel(tabDetails);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font);
        label_5->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label_5->setMargin(0);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_5);

        formLayout_3 = new QFormLayout();
        formLayout_3->setObjectName(QStringLiteral("formLayout_3"));
        label = new QLabel(tabDetails);
        label->setObjectName(QStringLiteral("label"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label);

        lblAttrRead = new QLabel(tabDetails);
        lblAttrRead->setObjectName(QStringLiteral("lblAttrRead"));

        formLayout_3->setWidget(0, QFormLayout::FieldRole, lblAttrRead);

        label_13 = new QLabel(tabDetails);
        label_13->setObjectName(QStringLiteral("label_13"));

        formLayout_3->setWidget(1, QFormLayout::LabelRole, label_13);

        lblAttrWrite = new QLabel(tabDetails);
        lblAttrWrite->setObjectName(QStringLiteral("lblAttrWrite"));

        formLayout_3->setWidget(1, QFormLayout::FieldRole, lblAttrWrite);

        label_14 = new QLabel(tabDetails);
        label_14->setObjectName(QStringLiteral("label_14"));

        formLayout_3->setWidget(2, QFormLayout::LabelRole, label_14);

        lblAttrExe = new QLabel(tabDetails);
        lblAttrExe->setObjectName(QStringLiteral("lblAttrExe"));

        formLayout_3->setWidget(2, QFormLayout::FieldRole, lblAttrExe);


        formLayout_2->setLayout(0, QFormLayout::FieldRole, formLayout_3);


        gridLayout_3->addLayout(formLayout_2, 0, 0, 1, 1);

        tabWidget->addTab(tabDetails, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);


        retranslateUi(FileProperties);
        QObject::connect(buttonBox, SIGNAL(accepted()), FileProperties, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), FileProperties, SLOT(reject()));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(FileProperties);
    } // setupUi

    void retranslateUi(QDialog *FileProperties)
    {
        FileProperties->setWindowTitle(QApplication::translate("FileProperties", "Dialog", 0));
        lblFileIcon->setText(QApplication::translate("FileProperties", "TextLabel", 0));
        lblFileInfo->setText(QApplication::translate("FileProperties", "TextLabel", 0));
        label_2->setText(QApplication::translate("FileProperties", "Type:", 0));
        lblFileType->setText(QApplication::translate("FileProperties", "TextLabel", 0));
        label_4->setText(QApplication::translate("FileProperties", "Location:", 0));
        lblFileLocation->setText(QApplication::translate("FileProperties", "TextLabel", 0));
        label_6->setText(QApplication::translate("FileProperties", "Size:", 0));
        lblFileSize->setText(QApplication::translate("FileProperties", "TextLabel", 0));
        lblFileCreated2->setText(QApplication::translate("FileProperties", "Created:", 0));
        lblFileCreated->setText(QApplication::translate("FileProperties", "TextLabel", 0));
        lblFileModified2->setText(QApplication::translate("FileProperties", "Modified:", 0));
        lblFileModified->setText(QApplication::translate("FileProperties", "TextLabel", 0));
        lblFileAccessed2->setText(QApplication::translate("FileProperties", "Last accessed:", 0));
        lblFileAccessed->setText(QApplication::translate("FileProperties", "TextLabel", 0));
        tabWidget->setTabText(tabWidget->indexOf(tabGeneral), QApplication::translate("FileProperties", "General", 0));
        tabWidget->setTabToolTip(tabWidget->indexOf(tabGeneral), QApplication::translate("FileProperties", "General", 0));
        label_5->setText(QApplication::translate("FileProperties", "Attributes:", 0));
        label->setText(QApplication::translate("FileProperties", "Read", 0));
        lblAttrRead->setText(QApplication::translate("FileProperties", "TextLabel", 0));
        label_13->setText(QApplication::translate("FileProperties", "Write", 0));
        lblAttrWrite->setText(QApplication::translate("FileProperties", "TextLabel", 0));
        label_14->setText(QApplication::translate("FileProperties", "Execute:", 0));
        lblAttrExe->setText(QApplication::translate("FileProperties", "TextLabel", 0));
        tabWidget->setTabText(tabWidget->indexOf(tabDetails), QApplication::translate("FileProperties", "Details", 0));
        tabWidget->setTabToolTip(tabWidget->indexOf(tabDetails), QApplication::translate("FileProperties", "Details", 0));
    } // retranslateUi

};

namespace Ui {
    class FileProperties: public Ui_FileProperties {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILEPROPERTIES_H
