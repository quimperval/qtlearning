#include <QInputDialog>
#include <QtDebug>
#include "task.h"
#include "ui_task.h"

Task::Task(const QString& name, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Task)
{
    ui->setupUi(this);
    setName(name);
    //This creates the relation between the clicked event in the editButton
    //And the rename function
    connect(ui->editButton, &QPushButton::clicked, this, &Task::rename);
    //emit the removed signal
    connect(ui->removeButton, &QPushButton::clicked,
        //This is an anonymous inline function
        [this, &name]{
            qDebug() << "Trying to remove " <<  name;
            emit removed(this);
        });
}

Task::~Task()
{
    delete ui;
}

void Task::setName(const QString& name)
{
    ui->checkBox->setText(name);
}

QString Task::name() const
{
    return ui->checkBox->text();
}

bool Task::isCompleted() const
{
    return ui->checkBox->isChecked();
}

void Task::rename(){
    bool ok;
    QString value = QInputDialog::getText(this, tr("Edit task"),
                                          tr("Task name"),
                                          QLineEdit::Normal,
                                          this->name(), &ok);
    if(ok && !value.isEmpty())
    {
        setName(value);
    }
}
