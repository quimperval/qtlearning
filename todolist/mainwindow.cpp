#include <QDebug>
#include <QInputDialog>
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
    updateStatus();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addTask()
{
    bool ok;
    QString name = QInputDialog::getText(this,
                    tr("Add task"),
                    tr("Task name"),
                    QLineEdit::Normal,
                    tr("Untitled task"),&ok);

    if(ok && !name.isEmpty()){
        qDebug() << "User clicked on the button";
        qDebug() << "Task name: " << name << "\n";
        Task* task = new Task(name);
        //This connects the removed signal to the remove task slot/receiver
        connect(task,&Task::removed,
                this,&MainWindow::removeTask);
        connect(task, &Task::statusChanged,
                this, &MainWindow::taskStatusChanged);
        mTasks.append(task);
        ui->tasksLayout->addWidget(task);
        updateStatus();
    }
}

void MainWindow::removeTask(Task* task)
{
    mTasks.removeOne(task);
    ui->tasksLayout->removeWidget(task);
    task->setParent(0);
    delete task;
    updateStatus();
}

void MainWindow::taskStatusChanged(Task* /*task*/){
    updateStatus();
}

void MainWindow::updateStatus()
{
    int completedCount=0;
    for(auto t: mTasks){
        if(t->isCompleted()){
            completedCount++;
        }
    }
    int todoCount = mTasks.size()- completedCount;
    ui->statusLabel->setText(QString("Status: %1 todo / %2 completed").arg(todoCount).arg(completedCount));
}
