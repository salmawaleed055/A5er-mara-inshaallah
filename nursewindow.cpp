#include "nursewindow.h"
#include "ui_nursewindow.h"
#include "nurse.h"
#include <QMessageBox>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QBrush>
#include <QPixmap>
#include "MainWindow.h"
#include "users.h"
#include "scheduleedit.h"

nursewindow::nursewindow(QWidget *parent,QString n)
    : QDialog(parent)
    , ui(new Ui::nursewindow)
{
    ui->setupUi(this);
    for (int i=0;i<nurses.size();i++)
    {
        if (nurses[i].username==n){
            nur=&nurses[i];
            break;
        }
    }
    ui->label_Hellonur->setText("Hello nurse. "+ nur->username);
    QPixmap backgroundImage(":/Images/download.jpg");

    // Set the background image
    QBrush backgroundBrush(backgroundImage);
    QPalette palette = this->palette();
    palette.setBrush(QPalette::Window, backgroundBrush);
    this->setPalette(palette);

}

nursewindow::~nursewindow()
{
    delete ui;
}

void nursewindow::on_pushButton_profile_clicked()
{
    QMessageBox::information(this, tr("profile"), "Name: "+ nur->username + "\nGender: "+nur->gender +
                                                      "\nAge: "+ QString::number(nur->age) + "\nWorking day: "+ nur->days.join(", ") + "time from: "+ QString::number(nur->starttime)
                                                      + " to "+ QString::number(nur->endtime));
}


QString nursewindow::getAssignmentString(nurse& nuu)
{
    QString assignmentString;
    for (const auto& patient : nuu.patients)  //assignments instead of patients
    {
        assignmentString += patient + ", ";
    }
    if (!assignmentString.isEmpty())
    {
        assignmentString.chop(2); // Remove the trailing ", "
    }
    return assignmentString;
}
void nursewindow::on_pushButton_Schedule_clicked()
{
    QString scheduleText;
    for (const auto& day : nur->days)
    {
        scheduleText += day + " - " + QString::number(nur->starttime) + ":00 to " + QString::number(nur->endtime) + ":00\n";
    }
    // for (const auto& patient : nur.patients)
    // {
    //     scheduleText += patient + "\n";
    // }
    QMessageBox::information(this, tr("Schedule"), scheduleText);
}


void nursewindow::on_pushButton_Assignment_clicked()
{
    QString drname = " ";
    if (doctors.empty() || nurses.empty()) {
        drname = "No doctors or nurses available";
    } else {
        bool match = false;
        for (int i=0;i<doctors.size();i++){

            if (doctors[i].starttime==nur->starttime && doctors[i].days == nur->days) {
                drname += "You will work with Dr. " + doctors[i].username + "\n";
                match = true;
                break; // Break out of the inner loop once a match is found
            }

        }
        if(!match)
            drname = "You will not work with doctors right now\n";
    }
    QMessageBox::information(this, tr("Assignment"),drname);

}


void nursewindow::on_pushButton_clicked()
{
    hide();
    MainWindow* win=new MainWindow(this);
    win->show();
}


void nursewindow::on_pushButton_editschedule_clicked()
{
    hide();
    scheduleedit* edit = new scheduleedit(this, nur->username);
    edit->show();
}

