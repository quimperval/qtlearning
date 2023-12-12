#ifndef SYSINFOLINUXIMPL_H
#define SYSINFOLINUXIMPL_H

#include <QtGlobal>
#include <QVector>

#include "SysInfo.h"

class SysInfoLinuxImpl : public SysInfo
{
    public:
        SysInfoLinuxImpl();
        void init() override;
        double cpuLoadAverage() override;
        double memoryUsed() override;
    private:
        //This function will perform the Linux API call to
        //retrieve timing information and return values in
        //a QVector class of qulonglong type.
        QVector<qulonglong> cpuRawData();

    private:
        //This variable stores a sample of system timing at a
        //given moment
        QVector<qulonglong> mCpuLoadLastValues;
};

#endif // SYSINFOLINUXIMPL_H
