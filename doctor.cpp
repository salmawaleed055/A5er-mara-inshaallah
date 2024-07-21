#include "doctor.h"
#include "ui_doctor.h"
#include "drclass.h"
#include <QFile>
#include <QMessageBox>
#include <QString>
#include "MainWindow.h"
#include "users.h"
#include "scheduleedit.h"

doctor::doctor(QWidget *parent, QString docname)
    : QDialog(parent)

    , ui(new Ui::doctor)

{
    ui->setupUi(this);
    for (int i=0;i<doctors.size();i++)
    {
        if (doctors[i].username==docname){
            currdoc=&doctors[i];
            break;
        }
    }
    currdoc->dpatients.clear();
    QString spec=currdoc->specialization;
    for (int i=0;i<patients.size();i++)
    {
        for (auto it=patients[i].appointments.begin();it!=patients[i].appointments.end();it++)
        {
            if (it.key()==spec)
            {
                if (it.value().contains(currdoc->username)){
                    currdoc->dpatients.push_back(patients[i].username);
                }
            }
        }
    }
    ui->label_HelloDr->setText("Hello Dr. "+ currdoc->username);
    QPixmap backgroundImage(":/Images/download.jpg");

    // Set the background image
    QBrush backgroundBrush(backgroundImage);
    QPalette palette = this->palette();
    palette.setBrush(QPalette::Window, backgroundBrush);
    this->setPalette(palette);
}

doctor::~doctor()
{
    delete ui;
}

void doctor::on_pushButton_profile_clicked()
{
   // QString profile = "Name: "+currdoc.username;
    ///continue
    QMessageBox::information(this, tr("profile"), "Name: "+ currdoc->username +"\nSpecialization" + currdoc->specialization + "\nGender: "+currdoc->gender +
                                                     "\nAge: "+ QString::number(currdoc->age) + "\nWorking day: "+ currdoc->days.join(", ") + "time from: "+ QString::number(currdoc->starttime)
                                                     + " to "+ QString::number(currdoc->endtime));
}



// QString doctor::getAssignmentString(drclass& doc)
// {
//     QString assignmentString;
//     for (const auto& patient : doc.dpatients)  //assignments instead of patients
//     {
//         assignmentString += patient + ", ";
//     }
//     if (!assignmentString.isEmpty())
//     {
//         assignmentString.chop(2); // Remove the trailing ", "
//     }
//     return assignmentString;
// }
// void doctor::updateAssignments(const patient& pat) {       ///////////////////////////////////
//     // Check if the doctor has an appointment with the patient
//     for (auto it = pat.appointments.begin(); it!= pat.appointments.end(); ++it) {
//         if (it.value() == currdoc.username) {
//             // Add the patient to the doctor's assignment list
//             currdoc.patients.append(pat.name);
//             break;
//         }
//     }
// }

void doctor::on_pushButton_profile_2_clicked()
{
    QString patientList="";
    for (const auto& pat : currdoc->dpatients)
    {
        patientList = patientList + pat + "\n";
    }
    QMessageBox::information(this, tr("Patient List"), "Patients:\n" + patientList);
   // QString assignmentString = getAssignmentString(currdoc);                /////////
    //QMessageBox::information(this, tr("Assignments"), assignmentString);
}


void doctor::on_pushButton_schedule_clicked()
{
    QString scheduleText;
    for (const auto& day : currdoc->days)
    {
        scheduleText += day + " - " + QString::number(currdoc->starttime) + ":00 to " + QString::number(currdoc->endtime) + ":00\n";
    }
    // for (const auto& patient : currdoc->dpatients)
    // {
    //     scheduleText += patient + "\n";
    // }
    QMessageBox::information(this, tr("Schedule"), scheduleText);
}


void doctor::on_pushButton_clicked()
{
    hide();
    MainWindow* win=new MainWindow(this);
    win->show();
}


void doctor::on_pushButton_editschedule_clicked()
{
    hide();
    scheduleedit* edit = new scheduleedit(this, currdoc->username);
    edit->show();
}

