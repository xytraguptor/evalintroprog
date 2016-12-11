#ifndef QFEXSEARCH_H
#define QFEXSEARCH_H

#include "QString"
#include "QFileSystemModel"

namespace QFeX {
class QFeXSearch;
}


class QFeXSearch
{
public:
    QFeXSearch();
   static QFileSystemModel* getFilteredFiles(QString, QString, int,QString, bool, bool, bool);
};

#endif // QFEXSEARCH_H
