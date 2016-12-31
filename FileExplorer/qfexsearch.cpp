#include "qfexsearch.h"
#include "QString"
#include "QFileSystemModel"

QFeXSearch::QFeXSearch()
{
    
}

QFileSystemModel* QFeXSearch::getFilteredFiles(QString searchQuery, QString searchPath, int dirDepth, QString searchText,bool isCaseSensitive, bool showLineNumbers, bool showFilePath){
    QFileSystemModel *modelDirectories = new QFileSystemModel;
    //QFileSystemModel *modelDirectories = new QFileSystemModel(this);
    modelDirectories->setRootPath(searchPath);
    modelDirectories->setFilter(QDir::NoDotAndDotDot | QDir::Files |QDir::Hidden);
    return modelDirectories;
    
}
