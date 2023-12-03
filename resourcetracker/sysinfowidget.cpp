#include "sysinfowidget.h"
#include <QVBoxLayout>

using namespace QtCharts;

SysInfoWidget::SysInfoWidget(QWidget *parent, int startDelayMs,
                             int updateSeriesDelayMs) : QWidget(parent), mChartView(this)
{
    //Initialization to define the timer interval and the slot to call whenever a timeout
    //signal is triggered
    mRefreshTimer.setInterval(updateSeriesDelayMs);
    connect(&mRefreshTimer, &QTimer::timeout, this,
            &SysInfoWidget::updateSeries);
    //This will start the real timer after a delay defined by startDelayMs
    QTimer::singleShot(startDelayMs, [this]{mRefreshTimer.start(); });

    mChartView.setRenderHint(QPainter::Antialiasing);
    mChartView.chart()->legend()->setVisible(false);

    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(&mChartView);
    setLayout(layout);
}

QChartView& SysInfoWidget::chartView(){
    return mChartView;
}
