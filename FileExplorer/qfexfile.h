#ifndef QFEXFILE_H
#define QFEXFILE_H

#include "QFileSystemModel"
#include "QTextStream"
#include "QDir"


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
    static bool saveContent(QString, QString);
};

#endif // QFEXFILE_H
