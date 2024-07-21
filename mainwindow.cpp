#include "mainwindow.h"
#include "patientmanagmentwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include "registering.h"
#include "users.h"
#include "adminwindow.h"
#include "admin.h"
#include "doctor.h"
#include "nursewindow.h"
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QBrush>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    imageLabel = new QLabel(this);

    QPixmap pix(":/Images/hospital.jpg");
    QPixmap backgroundImage(":/Images/download.jpg");

    //Set the background image
    QBrush backgroundBrush(backgroundImage);
    QPalette palette = this->palette();
    palette.setBrush(QPalette::Window, backgroundBrush);
    this->setPalette(palette);

    int w = ui->labelimagelogin->width();
    int h = ui->labelimagelogin->height();
    ui->labelimagelogin->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
    ui->labelimagelogin->setVisible(true);
    ui->error->setVisible(false);

    //Nutrition,OG,IM,Ophthalmology,Dermatology
    //QObject::connect(&PatientManagmentWindow, &PatientManagmentWindow::elementAdded, this, &MainWindow::updateMap);
    for (int i=0;i<doctors.size();i++)
    {
        if (doctors[i].specialization=="Nutrition")
        {
            bool found=false;
            for (int j=0;j<Nutrition.size();j++)
            {
                if (doctors[i].username==Nutrition[j]->username)
                    found=true;
            }
            if (!found)
                Nutrition.push_back(&doctors[i]);


        }
        else if (doctors[i].specialization=="OG")
        {
            bool found=false;
            for (int j=0;j<OG.size();j++)
            {
                if (doctors[i].username==OG[j]->username)
                    found =true;
            }
            if (!found)
                OG.push_back(&doctors[i]);


        }
        else if (doctors[i].specialization=="IM")
        {
            bool found=false;
            for (int j=0;j<IM.size();j++)
            {
                if (doctors[i].username==IM[j]->username)
                    found=true;
            }
            if (!found)
                IM.push_back(&doctors[i]);
        }
        else if (doctors[i].specialization=="Dermatology")
        {
            bool found=false;
            for (int j=0;j<Derm.size();j++)
            {
                if (doctors[i].username==Derm[j]->username)
                    found=true;
            }
            if (!found)
                Derm.push_back(&doctors[i]);

        }
        else if (doctors[i].specialization=="Ophthalmology")
        {
            bool found=false;
            for (int j=0;j<oph.size();j++)
            {
                if (doctors[i].username==oph[j]->username)
                    found=true;
            }
            if (!found)
                oph.push_back(&doctors[i]);

        }

    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::setpatapp(QMap<QString,QString> m, QString n){

    {
        for (int i=0;i<patients.size();i++)
        {
            if (patients[i].username==n)
            {
                for (auto it=m.begin();it!=m.end();it++)
                {
                    if (!patients[i].appointments.count(it.key()))
                        patients[i].appointments.insert(it.key(),it.value());
                }
            }
        }
        m.clear();
    }

}
void MainWindow::on_pushButtonLogin_clicked()
{

    for (int i = 0; i < patients.size(); ++i) {
        if (patients[i].username == ui->lineEditUsername->text() && patients[i].pass == ui->lineEditPassword->text()) {

            hide();
            PatientManagmentWindow* patientWindow = new PatientManagmentWindow(this,patients[i].username);
            patientWindow->show();

            return;
        }
    }

    for (int i=0;i < admins.size() ;i++)
    {
        if (admins[i].username==ui->lineEditUsername->text() && admins[i].pass==ui->lineEditPassword->text())
        {
            hide();
            adminwindow* add=new adminwindow(this,admins[i]);
            add->show();
            return;

        }
    }
    for (int i=0;i < doctors.size() ;i++)
    {
        if (doctors[i].username==ui->lineEditUsername->text() && doctors[i].pass==ui->lineEditPassword->text())
        {
            hide();
            doctor* add=new doctor(this,doctors[i].username);
            add->show();
            return;

        }
    }
    for (int i=0;i < nurses.size() ;i++)
    {
        if (nurses[i].username==ui->lineEditUsername->text() && nurses[i].pass==ui->lineEditPassword->text())
        {
            hide();
            nursewindow* add=new nursewindow(this,nurses[i].username);
            add->show();
            return;

        }
    }
    ui->error->setVisible(true);
}

// void MainWindow::updateMap(const QString &key, const QString &value, QString n) {
//     for (int i=0;i<patients.size();i++)
//     {
//         if (patients[i].username==n)
//             patients[i].appointments.insert(key, value);
//     }

//     // Update UI or perform any necessary actions with myMap
// }
void MainWindow::on_PushbuttonRegister_clicked()
{
    hide();
    registering* reg = new registering(this);
    reg->show();
}

