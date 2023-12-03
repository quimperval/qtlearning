#ifndef SYSINFOWIDGET_H
#define SYSINFOWIDGET_H

#include <QWidget>
#include <QTimer>
#include <QtCharts/QChartView>

class SysInfoWidget : public QWidget
{
    Q_OBJECT;

    public:
        explicit SysInfoWidget(QWidget *parent=0, int startDelayMs = 500,
                               int updateSeriesDelayMs= 500);
    protected:
        QtCharts::QChartView& chartView();

    protected slots:
        virtual void updateSeries() = 0;

    private:
        //This will call the slot function updateSeries regularly
        QTimer mRefreshTimer;
        //QChartView is the generic widget that can display many types of chart.
        //This class will handle the layout and display the QChartView
        QtCharts::QChartView mChartView;
};

#endif // SYSINFOWIDGET_H
