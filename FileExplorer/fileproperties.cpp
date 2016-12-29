#include "fileproperties.h"
#include "ui_fileproperties.h"
#include "qfexpath.h"
#include "QDateTime"

FileProperties::FileProperties(QWidget *parent, QList<QFileInfo> *files) :
    QDialog(parent),
    ui(new Ui::FileProperties)
{
    ui->setupUi(this);
    fileInfoList = files;
    //remove "?" button in title bar
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    setFormData();
}

FileProperties::~FileProperties()
{
    delete ui;
}

void FileProperties::on_buttonBox_clicked(QAbstractButton *button)
{
    this->close();
}

void FileProperties::setFormData()
{
    QString windowTitle = "";
    QString fileType = "";
    QString fileLocation = "";
    QString fileSize = "";
    
    
    if(fileInfoList!=NULL){
        if(fileInfoList->count()==1){
            QFileInfo file = fileInfoList->at(0);
            
            //set window title
            windowTitle = file.fileName();
            
            /*GENERAL tab*/
            //set icon & text
            QPixmap* pix = new QPixmap(":/ico/Resources/file-24.png");
            ui->lblFileIcon->setPixmap(*pix);
            ui->lblFileIcon->setScaledContents(true);
            delete pix;
            ui->lblFileInfo->setText(file.fileName());
            
            //set Type
            ui->lblFileType->setText("."+file.suffix().toLower());
            //set Location
            ui->lblFileLocation->setText(QFeXPath::getWindowsStylePath(file.absolutePath()));
            //set Size
            ui->lblFileSize->setText(QFeXPath::getFileSize(file.size()));
            //set Created date
            ui->lblFileCreated->setText(file.created().toString("ddd d MMMM yyyy, hh:mm"));
            //set Modified date
            ui->lblFileModified->setText(file.lastModified().toString("ddd d MMMM yyyy, hh:mm"));
            //set Last Accessed date
            ui->lblFileAccessed->setText(file.lastRead().toString("ddd d MMMM yyyy, hh:mm"));
            
            /*DETAILS tab*/
            //set Attributes
            ui->lblAttrRead->setText(file.permission(QFile::ReadUser)? "True":"False");
            ui->lblAttrWrite->setText(file.permission(QFile::WriteUser)? "True":"False");
            ui->lblAttrExe->setText(file.permission(QFile::ExeUser)? "True":"False");
            
        }else{
            //set window title
            windowTitle = QString("%1 selected files").arg((int)fileInfoList->count());
            
            /*GENERAL tab*/
            //set icon & text
            QPixmap* pix = new QPixmap(":/ico/Resources/files-24.png");
            ui->lblFileIcon->setPixmap(*pix);
            ui->lblFileIcon->setScaledContents(true);
            delete pix;
            ui->lblFileInfo->setText(windowTitle);
            
            //set Location
            ui->lblFileLocation->setText(QFeXPath::getWindowsStylePath(fileInfoList->at(0).absolutePath()));
            
            QString types;
            qint64 size = 0;
            foreach(QFileInfo f, *fileInfoList){
                types.append(QString(".%1, ").arg(f.suffix().toLower()));
                size += f.size();
            }
            
            //set Type
            ui->lblFileType->setText(types);
            
            //set Size
            ui->lblFileSize->setText(QFeXPath::getFileSize(size));
            
            /*hide unnecessary fields*/
            //set Created date
            ui->lblFileCreated->setHidden(true);
            ui->lblFileCreated2->setHidden(true);
            //set Modified date
            ui->lblFileModified->setHidden(true);
            ui->lblFileModified2->setHidden(true);
            //set Last Accessed date
            ui->lblFileAccessed->setHidden(true);
            ui->lblFileAccessed2->setHidden(true);
            
            /*DETAILS tab -> hide*/
            ui->tabWidget->removeTab(1);
        }
    }
    
    this->setWindowTitle(windowTitle);
}
