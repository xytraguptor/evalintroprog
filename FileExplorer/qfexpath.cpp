#include "qfexpath.h"
#include "QString"
#include "QVariant"


QFeXPath::QFeXPath()
{

}

QString QFeXPath::getRootPath()
{
#if defined(Q_OS_UNIX)
    return QLatin1String("/");
#elif defined(Q_OS_LINUX)
    return QLatin1String("/");
#elif defined(Q_OS_WIN)
    return QLatin1String("");
#else
    return QLatin1String("");
#endif
}
QString QFeXPath::getWindowsStylePath(QString path)
{
    return path.replace("/", "\\");
}

QString QFeXPath::getFileSize(qint64 size)
{
    QString result;
    long double kilobyte;
    long double megabyte;
    long double gigabyte;

    kilobyte = size / 1024;
    megabyte = kilobyte / 1024;
    gigabyte = megabyte /  1024;

    if((int)gigabyte > 0)
    {
        result.append(QString("%1 GB").arg((double)gigabyte));
    } else if((int)megabyte > 0)
    {
        result.append(QString("%1 MB").arg((double)megabyte));
    } else if((int)kilobyte > 0)
    {
        result.append(QString("%1 KB").arg((double)kilobyte));
    } else{
        result.append(QString("%1 bytes").arg((double)size));
    }

    return result;
}
