#ifndef QFEXPATH_H
#define QFEXPATH_H

#include "QString"

namespace QFeX {
class QFeXPath;
}

class QFeXPath
{
public:
    QFeXPath();
    static QString getRootPath();
    static QString getWindowsStylePath(QString);
    static QString getFileSize(qint64);
};

#endif // QFEXPATH_H
