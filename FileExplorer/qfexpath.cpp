#include "qfexpath.h"
#include "QString"


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
