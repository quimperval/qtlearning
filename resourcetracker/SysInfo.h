#ifndef SYSINFO_H
#define SYSINFO_H

class SysInfo
{
	
	public:
		SysInfo();
        virtual ~SysInfo();
		//The virtual keyword means the function can be overriden in a derived class.
		//The =0 means that this function is pure virtual and must be overriden in any concrete derived class.
		virtual void init() = 0;
		virtual double cpuLoadAverage() = 0;
		virtual double memoryUsed() = 0;
	
};

#endif //SYSINFO_H
