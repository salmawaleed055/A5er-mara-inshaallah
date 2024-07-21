#include "patientmanagmentwindow.h"
#include "ui_patientmanagmentwindow.h"
#include <rescheduleappointmentwindow.h>
#include <bookappointmentwindow.h>
#include <cancelappointmentwindow.h>
#include <chat.h>
#include <qpixmap.h>
#include<mainwindow.h>
#include <QTextStream>
#include <QFile>
#include <QMessageBox>
#include <patient.h>
#include "users.h"


PatientManagmentWindow::PatientManagmentWindow(QWidget *parent,QString patname) :
    QDialog(parent),
    ui(new Ui::PatientManagmentWindow),

    submit(false)
{
    QPixmap backgroundImage(":/Images/download.jpg");
    for (int i=0;i<patients.size();i++)
    {
        if (patients[i].username==patname){
            currentPatient=&patients[i];
            break;
        }
    }

    QBrush backgroundBrush(backgroundImage);
    QPalette palette = this->palette();
    palette.setBrush(QPalette::Window, backgroundBrush);
    this->setPalette(palette);

    ui->setupUi(this);

    ui->comboBoxCancel->setVisible(false);
    ui->comboBoxReschedule->setVisible(false);
    ui->pushButtonSubmit->setVisible(false);
    ui->labelHello_2->setText("Hello "+patname);


    updateComboBoxes();
}

PatientManagmentWindow::~PatientManagmentWindow()
{
    delete ui;
}
void PatientManagmentWindow::setUsername(const QString &username)
{
    QFont font1;
    font1.setFamily("Arial");
    font1.setPointSize(9);
    font1.setItalic(true);
    font1.setBold(true);

    QFont font2;
    font2.setFamily("Segoe UI");
    font2.setPointSize(16);
    ui->labelUsername->setFont(font1); // Apply the first font
    ui->labelUsername->setText(username);
    ui->labelUsername->setFont(font2); // Apply the second font
}
void PatientManagmentWindow::on_pushButtonBook_clicked()
{
    hide();
    BookAppointmentWindow* book = new BookAppointmentWindow(this,currentPatient->username);
    book->show();

}


void PatientManagmentWindow::on_pushButtonReschedule_clicked()
{
    ui->comboBoxReschedule->setVisible(true);
    ui->pushButtonSubmit->setVisible(true);
    ui->pushButtonCancel->setEnabled(false);
}


void PatientManagmentWindow::on_pushButtonCancel_clicked()
{
    ui->comboBoxCancel->setVisible(true);
    ui->pushButtonSubmit->setVisible(true);
    ui->pushButtonReschedule->setEnabled(false);
}

void PatientManagmentWindow::on_pushButtonChat_clicked()
{
    chat* chat =new class chat (this);
    chat->show();
}

void PatientManagmentWindow::on_pushButtonMedical_Record_clicked()
{
    QString filePath = ":/Medical record file/medical record.txt";
QString medicalRecord;

if (!filePath.isEmpty()) {
    QFile file(filePath);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        QString line;
        bool found = false;
        while (!in.atEnd()) {
            line = in.readLine().trimmed(); // Read and trim whitespace
            if (line.startsWith("Name: " + currentPatient->username)) {
                found = true;
                medicalRecord += line + "\n";
                while (!in.atEnd() && !line.isEmpty()) {
                    line = in.readLine().trimmed();
                    if (!line.isEmpty()) {
                        medicalRecord += line + "\n";
                    }
                }
                break;
            }
        }
        file.close();

        if (found) {
            QMessageBox::information(this, tr("Medical Record"), medicalRecord);
        } else {
            medicalRecord="Name: "+ currentPatient->username+"\nAge "+ QString::number(currentPatient->age)+"\nGender: "+currentPatient->gender+"\nNo Medical Record\n";
            QMessageBox::information(this, tr("Error"), medicalRecord);
        }
    } else {
        QMessageBox::critical(this, tr("Error"), tr("Failed to open the file."));
    }
}
}
void PatientManagmentWindow::updateComboBoxes()
{

    ui->comboBoxReschedule->clear();



    ui->comboBoxCancel->clear();

    for (auto it=currentPatient->appointments.begin();it!=currentPatient->appointments.end();it++)
    {
        ui->comboBoxCancel->addItem(it.key()+" - "+it.value());
        ui->comboBoxReschedule->addItem(it.key()+" - "+it.value());
    }


}


void PatientManagmentWindow::on_pushButtonSubmit_clicked()
{
    if (ui->comboBoxCancel->isVisible()) {
        int currentIndex = ui->comboBoxCancel->currentIndex();
        if (currentIndex >= 0) {
            QString selectedItem = ui->comboBoxCancel->itemText(currentIndex);
            currentPatient->appointments.remove(selectedItem.section(" - ", 0, 0));
            //currentPatient.appointments.remove(selectedItem);
            ui->comboBoxCancel->removeItem(currentIndex);
            ui->comboBoxReschedule->removeItem(currentIndex);
        }
        ui->comboBoxCancel->setVisible(false);
        ui->pushButtonSubmit->setVisible(false);
        ui->pushButtonReschedule->setEnabled(true);
    }

    if (ui->comboBoxReschedule->isVisible()) {
        int currentIndex = ui->comboBoxReschedule->currentIndex();
        if (currentIndex >= 0) {
            QString selectedItem = ui->comboBoxReschedule->itemText(currentIndex);
            currentPatient->appointments.remove(selectedItem.section(" - ", 0, 0));
            ui->comboBoxReschedule->removeItem(currentIndex);
            ui->comboBoxCancel->removeItem(currentIndex);
            BookAppointmentWindow* app = new BookAppointmentWindow(this,currentPatient->username);
            hide();
            app->show();

        }
    }
    ui->pushButtonCancel->setEnabled(true);
    ui->comboBoxReschedule->setVisible(false);

}


void PatientManagmentWindow::on_pushButton_clicked()
{
    hide();
    MainWindow* win=new MainWindow(this);

    win->show();

}


void PatientManagmentWindow::on_pushButtonMedical_Record_2_clicked()
{
    QString app="";
    for (auto it=currentPatient->appointments.begin();it!=currentPatient->appointments.end();it++)
    {
        app=app+it.key()+" - "+it.value()+"\n";
    }
    QMessageBox::information(this,"Appointments",app);
}

