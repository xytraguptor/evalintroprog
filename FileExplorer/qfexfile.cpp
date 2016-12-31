#include "qfexfile.h"


QFeXFile::QFeXFile()
{

}

bool QFeXFile::copy(QList<QFileInfo> *files, QString destinationPath)
{
    foreach(QFileInfo f, *files){
        if(f.isFile()){
            QString sourceFile = f.absoluteFilePath() ;
            QString destinationDir =  destinationPath + f.fileName();

            if (!QFile::copy(sourceFile, destinationDir)) {
                return false;
            }
        }
    }
    return true;
}
bool QFeXFile::move(QList<QFileInfo> *files, QString destinationPath)
{
    if(copy(files,destinationPath) && remove(files))
        return true;
    else
        return false;
}
bool QFeXFile::remove(QList<QFileInfo> *files)
{
    foreach(QFileInfo f, *files){
        if(f.isFile()){
            if (!QFile::remove(f.absoluteFilePath())) {
                return false;
            }
        }
    }
    return true;
}

bool QFeXFile::rename(QFileInfo file, QString newFileName)
{
    QString source = file.absoluteFilePath() ;
    QString destination =  file.absolutePath() + newFileName;
    return QFile::rename(source, destination);
}

bool QFeXFile::saveContent(QString content, QString fileName)
{
    bool result = false;

    if(fileName.isEmpty())
        return result;

    QFile file(fileName);
    if ( file.open(QIODevice::ReadWrite) )
    {
        QTextStream stream( &file );
        stream << content << endl;
        result = true;

    }
    return result;
}
