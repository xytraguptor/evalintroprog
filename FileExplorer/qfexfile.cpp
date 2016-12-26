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
