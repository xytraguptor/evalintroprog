#ifndef PATHOP_H
#define PATHOP_H

#include <stdio.h>  /* defines FILENAME_MAX */
#ifdef WINDOWS
#include <direct.h>
#define GetCurrentDir _getcwd
#else
#include <unistd.h>
#define GetCurrentDir getcwd
#endif



class pathop
{
    char cCurrentPath[FILENAME_MAX];

public:
    pathop();
    virtual ~pathop();
    pathop(const pathop& other);
    char getCurrentPath(void)
    {

        if (!GetCurrentDir(cCurrentPath, sizeof(cCurrentPath)))
        {
            return 0;
        }

        return cCurrentPath[sizeof(cCurrentPath) - 1] = '\0';
    };

protected:

private:



};


#endif // PATHOP_H
