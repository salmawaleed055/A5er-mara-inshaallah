#include "adminwindow.h"
#include "ui_adminwindow.h"
#include "admin.h"
#include "users.h"
#include "patientmanagmentwindow.h"
#include "doctor.h"
#include "nursewindow.h"
#include <QComboBox>
#include "mainwindow.h"

adminwindow::adminwindow(QWidget *parent,admin ad)
    : QDialog(parent)
    , ui(new Ui::adminwindow)
{
    ui->setupUi(this);
    QPixmap backgroundImage(":/Images/download.jpg");

    // Set the background image
    QBrush backgroundBrush(backgroundImage);
    QPalette palette = this->palette();
    palette.setBrush(QPalette::Window, backgroundBrush);
    this->setPalette(palette);

    ui->hello->setText("Hello "+ ad.username);
    ui->patbox->setVisible(false);
    ui->nursebox->setVisible(false);
    ui->doctorbox->setVisible(false);
    ui->doc->setVisible(false);
    ui->nurse->setVisible(false);

    for (int i=0;i<patients.size();i++)
        ui->patbox->addItem(patients[i].username);
    for (int i=0;i<doctors.size();i++)
        ui->doctorbox->addItem(doctors[i].username);
    for (int i=0;i<nurses.size();i++)
        ui->nursebox->addItem(nurses[i].username);
}

adminwindow::~adminwindow()
{
    delete ui;
}

void adminwindow::on_pat_clicked()
{
    ui->patbox->setVisible(true);
    ui->staff->setEnabled(false);
}


void adminwindow::on_staff_clicked()
{
    ui->nurse->setVisible(true);
    ui->doc->setVisible(true);
    ui->pat->setEnabled(false);
}


void adminwindow::on_submit_clicked()
{
    if (ui->nursebox->isVisible()){
        for (int i=0;i<nurses.size();i++)
            if (nurses[i].username==ui->nursebox->currentText())
            {
                hide();
                nursewindow* win=new nursewindow(this,nurses[i].username);
                win->show();
            }
    }
    if (ui->doctorbox->isVisible()){
        for (int i=0;i<doctors.size();i++)
            if (doctors[i].username==ui->doctorbox->currentText())
            {
                hide();
                doctor* win=new doctor(this,doctors[i].username);
                win->show();
            }
    }
    if (ui->patbox->isVisible()){
        for (int i=0;i<patients.size();i++)
            if (patients[i].username==ui->patbox->currentText())
            {
                hide();
                PatientManagmentWindow* win=new PatientManagmentWindow(this,patients[i].username);
                win->show();
            }
    }
}


void adminwindow::on_doc_clicked()
{
   ui->nurse->setEnabled(false);
   ui->doctorbox->setVisible(true);
}


void adminwindow::on_nurse_clicked()
{
   ui->doc->setEnabled(false);
   ui->nursebox->setVisible(true);
}


void adminwindow::on_pushButton_clicked()
{
    hide();
    MainWindow* win=new MainWindow(this);
    win->show();
}

