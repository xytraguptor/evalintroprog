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
};

#endif // QFEXFILE_H
