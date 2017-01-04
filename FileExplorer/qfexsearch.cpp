#include "qfexsearch.h"
#include "QString"
#include "QFileSystemModel"
#include <QObject>

QFeXSearch::QFeXSearch(){}
QFeXSearch::QFeXSearch(QString &_searchQuery, QString &_searchPath, int &_dirDepth, QString &_searchText,bool &_isCaseSensitive, bool &_showLineNumbers, bool &_showFilePath)
{
    this->setShowLineNumbers(_showLineNumbers);
    this->setDirDepth(_dirDepth);
    this->setIsCaseSensitive(_isCaseSensitive);
    this->setSearchPath(_searchPath);
    this->setSearchQuery(_searchQuery);
    this->setSearchText(_searchText);
    this->setShowFilePath(_showFilePath);
    _result = new QStringList();
}

QStringList QFeXSearch::getFilteredFiles(){

    searchFiles(this->searchQuery(), this->searchPath(), this->dirDepth(), _result);
    return *_result;
}

void QFeXSearch::searchFiles(QString query, QString path, int depth, QStringList *results){
    QDir currentDir(path);
    const QString parentPath = path.endsWith("/") ? path : path  + "/";

    if (this->dirDepth() != -1 && depth < 0)
           return;

    //build filters
    QStringList filters;

    if(query.isEmpty()) {
        filters << "*"; //search all
    } else {
        filters << "*" + query + "*";
    }

    foreach (const QString &match, currentDir.entryList(QStringList(filters), QDir::Files | QDir::NoSymLinks)){
        //match if case sensitive option is selected
        if(this->IsCaseSensitive()){
            //case sensitive
            if(match.contains(query, Qt::CaseSensitive)){
                results->append(parentPath + match);
            }
        }else{ //case insensitive
            results->append(parentPath + match);
        }
    }
    foreach (QString dir, currentDir.entryList(QDir::Dirs | QDir::NoSymLinks | QDir::NoDotAndDotDot)){

                QString newPath = parentPath + dir;
                searchFiles(query, newPath, depth-1, results);
    }
}
