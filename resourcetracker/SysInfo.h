#ifndef SYSINFO_H
#define SYSINFO_H

class SysInfo
{
	
	public:
        //This helps to create the singleton
        static SysInfo& instance();
        virtual ~SysInfo();
		//The virtual keyword means the function can be overriden in a derived class.
		//The =0 means that this function is pure virtual and must be overriden in any concrete derived class.
		virtual void init() = 0;
		virtual double cpuLoadAverage() = 0;
		virtual double memoryUsed() = 0;

    protected:
        //Making the constructor as protected, then only this and its child classes
        //will be allowed to call the constructor
        explicit SysInfo();

    private:
        SysInfo(const SysInfo& rhs);
        SysInfo& operator=(const SysInfo& rhs);
	
};

#endif //SYSINFO_H
