#ifndef QFEXFILE_H
#define QFEXFILE_H

#include "QFileSystemModel"


namespace QFeX {
class QFeXFile;
}
class QFeXFile
{
public:
    QFeXFile();
    static bool copy(QList<QFileInfo>*, QString);
    static bool move(QList<QFileInfo>*, QString);
    static bool remove(QList<QFileInfo>*);
    static bool rename(QFileInfo, QString);
};

#endif // QFEXFILE_H
