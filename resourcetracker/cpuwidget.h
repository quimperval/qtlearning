#ifndef CPUWIDGET_H
#define CPUWIDGET_H

#include <QtCharts/QPieSeries>

#include "sysinfowidget.h"
#include "SysInfo.h"

class CpuWidget : public SysInfoWidget
{
    //This macro allows CpuWidget to responde to
    //SysInfoWidgetmRefreshTimer::timeout()
    Q_OBJECT;

    public:
        explicit CpuWidget(QWidget* parent=0);

    protected slots:
        void updateSeries() override;

    private:
        QtCharts::QPieSeries* mSeries;
};

#endif // CPUWIDGET_H
