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

bool QFeXFile::remove(QList<QFileInfo> *files)
{
    foreach(QFileInfo f, *files){
        if(f.isFile()){
            QString sourceFile = f.absoluteFilePath() ;

           // QFile file (dbFile);
           //     file.remove();

            if (!QFile::remove(f.absoluteFilePath())) {
                return false;
            }
        }
    }
    return true;
}
