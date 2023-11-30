#include <QDebug>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
      mTasks()
{
    ui->setupUi(this);
    /**
     * sender is the object that will send the signal.
     * &Sender::signalName is the pointer to the member signal
     * function. Something will be launched when the signal is triggered.
     * receiver is the object that will receive and handle the signal.
     * &Receiver::slotName is a pointer to one of the receiver's member
     * slot function
     * */

    //connect(sender, &Sender::signalName,
        // receiver, &Receiver::slotName);

    //ui->addTaskButton is the sender
    //&QPushButton::clicked is the signalName
    //this is the receiver
    //&MainWindow::addTask is the slotName, the function that will be executed
    //when the sender sends the signal.
    connect(ui->addTaskButton, &QPushButton::clicked,
            this, &MainWindow::addTask);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addTask()
{
    qDebug() << "User clicked on the button";
    Task* task = new Task("Untitled task");
    mTasks.append(task);
    ui->tasksLayout->addWidget(task);
}

