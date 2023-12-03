//This is to use qulonglong
#ifndef SYSINFOWINDOWSIMPL_H
#define SYSINFOWINDOWSIMPL_H
#include <QtGlobal>
#include <QVector>

#include "SysInfo.h"

typedef struct _FILETIME FILETIME;

class SysInfoWindowsImpl : public SysInfo
{
	public:
		SysInfoWindowsImpl();
		//override keyword here ensures that the function is declared as virtual in the base class. 
		//If the function signature marked as override does not match any parent class' virtual function a compile 
		//error will be displayed
		void init() override;
		double cpuLoadAverage() override;
		double memoryUsed() override;
	
	private: 
		//This function performs the Windows API call to retrieve system timing information.
		QVector<qulonglong> cpuRawData();
		qulonglong convertFileTime(const FILETIME& filetime) const;
	
	private:
		//This will store system timing 
        QVector<qulonglong> mCpuLoadLastValues;
};
#endif // SYSINFOWINDOWSIMPL_H
