#include <QtGlobal>
#include "SysInfo.h"

#ifdef Q_OS_WIN
    #include "SysInfoWindowsImpl.h"
#endif

SysInfo& SysInfo::instance()
{
#ifdef Q_OS_WIN
    static SysInfoWindowsImpl singleton;
#endif
    return singleton;
}

SysInfo::SysInfo()
{

}

SysInfo::~SysInfo()
{
	
}
