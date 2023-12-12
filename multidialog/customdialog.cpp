#include "customdialog.h"

#include <QDebug>

CustomDialog::CustomDialog(QWidget *parent) : QDialog(parent)
{
    qDebug() << "Instantiating CustomDialog";
    this->resize(200,200);
}
