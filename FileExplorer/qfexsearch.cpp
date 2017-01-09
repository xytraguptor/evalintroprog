#include "qfexsearch.h"
#include "QString"
#include "QFileSystemModel"
#include <QObject>

QFeXSearch::QFeXSearch(){}
QFeXSearch::QFeXSearch(QString &_searchQuery, QString &_searchPath, int &_dirDepth, QString &_searchText,bool &_isCaseSensitive, bool &_showLineNumbers, bool &_showFilePath, bool &_isTextCaseSensitive)
{
    this->setShowLineNumbers(_showLineNumbers);
    this->setDirDepth(_dirDepth);
    this->setIsCaseSensitive(_isCaseSensitive);
    this->setIsTextCaseSensitive(_isTextCaseSensitive);
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

    //directory depth omiting -1(All) option
    if (this->dirDepth() != -1 && depth < 0)
        return;

    QString matchedFilePath = "";

    //build filters
    QStringList filters;
    if(query.isEmpty()) {
        filters << "*"; //search all
    } else {
        filters << "*" + query + "*";
    }

    foreach (const QString &match, currentDir.entryList(QStringList(filters), QDir::Files | QDir::NoSymLinks)){
        matchedFilePath = "";
        //match if case sensitive option is selected
        if(this->IsCaseSensitive()){
            //case sensitive
            if(match.contains(query, Qt::CaseSensitive)){
                matchedFilePath = parentPath + match;
            }
        }else{ //case insensitive
            matchedFilePath = parentPath + match;
        }

        if(!matchedFilePath.isEmpty()){

            if(!this->searchText().isNull()){
                if(searchInFile(matchedFilePath, this->searchText())> 0)
                    results->append(matchedFilePath);
            }else{
                results->append(matchedFilePath);
            }
        }
    }
    //search subfolders
    foreach (QString dir, currentDir.entryList(QDir::Dirs | QDir::NoSymLinks | QDir::NoDotAndDotDot)){
        QString newPath = parentPath + dir;
        searchFiles(query, newPath, depth-1, results);
    }
}

int QFeXSearch::searchInFile(QString filePath, QString searchString){
    QFile file(filePath);
    file.open(QIODevice::ReadWrite);
    QTextStream in (&file);
    QString line;
    int linenumber = -1;
    int it = 0;
        do {

            line = in.readLine();
            it++;
            if (line.contains(searchString, this->IsTextCaseSensitive() ? Qt::CaseSensitive : Qt::CaseInsensitive)) {
                linenumber = it;
                break;
            }
        } while (!line.isNull());

        file.close();


    return linenumber;
}
