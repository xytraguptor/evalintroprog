#ifndef QFEXSEARCH_H
#define QFEXSEARCH_H

#include "QString"
#include "QFileSystemModel"
#include "qfexpath.h"
#include <QObject>
#include <QDialog>
#include "QTextStream"
#include <io.h>

namespace QFeX {
class QFeXSearch;
}


class QFeXSearch : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString searchPath READ searchPath WRITE setSearchPath)

public:

    explicit QFeXSearch();
    QFeXSearch(QString &_searchQuery, QString &searchPath, int &dirDepth, QString &searchText, bool &isCaseSensitive, bool &showLineNumbers, bool &showFilePath, bool &_isTextCaseSensitive);
    //
    QStringList getFilteredFiles();

    void setSearchPath(QString searchPath) {_searchPath = searchPath;}
    QString searchPath() const { return _searchPath; }

    void setSearchQuery(QString searchQuery) {_searchQuery = searchQuery;}
    QString searchQuery() const { return _searchQuery; }

    void setDirDepth(int dirDepth) {_dirDepth = dirDepth;}
    int dirDepth() const { return _dirDepth; }

    void setSearchText(QString searchText) {_searchText = searchText;}
    QString searchText() const { return _searchText; }

    void setIsCaseSensitive(bool isCaseSensitive) {_isCaseSensitive = isCaseSensitive;}
    bool IsCaseSensitive() const { return _isCaseSensitive; }

    void setShowFilePath(bool showFilePath) {_showFilePath = showFilePath;}
    bool ShowFilePath() const { return _showFilePath; }

    void setShowLineNumbers(bool showLineNumbers) {_showLineNumbers = showLineNumbers;}
    bool ShowLineNumbers() const { return _showLineNumbers; }

    void setIsTextCaseSensitive(bool isTextCaseSensitive) {_isTextCaseSensitive = isTextCaseSensitive;}
    bool IsTextCaseSensitive() const { return _isTextCaseSensitive; }

    //~QFeXSearch();
private:
    QString _searchQuery;
    QString _searchPath;
    int _dirDepth;
    QString _searchText;
    bool _isCaseSensitive;
    bool _isTextCaseSensitive;
    bool _showLineNumbers;
    bool _showFilePath;
    QStringList *_result;
    void searchFiles(QString query, QString path, int depth, QStringList*results);
    int QFeXSearch::searchInFile(QString filePath, QString searchString);
};

#endif // QFEXSEARCH_H
