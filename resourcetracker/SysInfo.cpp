#include <QtGlobal>
#include "SysInfo.h"

#ifdef Q_OS_WIN
    #include "SysInfoWindowsImpl.h"
#elif defined(Q_OS_LINUX)
    #include "SysInfoLinuxImpl.h"
#endif

SysInfo& SysInfo::instance()
{
#ifdef Q_OS_WIN
    static SysInfoWindowsImpl singleton;
#elif defined(Q_OS_LINUX)
    static SysInfoLinuxImpl singleton;
#endif
    return singleton;
}

SysInfo::SysInfo()
{

}

SysInfo::~SysInfo()
{
	
}
