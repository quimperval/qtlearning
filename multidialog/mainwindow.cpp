#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    QPushButton *button = new QPushButton(this);
    button->setGeometry(0,0,120,48);
    button->setText("Click me");
    connect(button, &QPushButton::clicked, this, &MainWindow::openDialog);
    this->resize(500,500);
}

MainWindow::~MainWindow()
{

}

void MainWindow::openDialog()
{
    qDebug() << "Opening dialog";
    CustomDialog dialog(this);
    dialog.exec();
}

