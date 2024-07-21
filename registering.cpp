#include "registering.h"
#include "ui_registering.h"
#include "users.h"
#include "mainwindow.h"
#include "patient.h"
#include "drclass.h"

registering::registering(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::registering)
{
    ui->setupUi(this);
    ui->errorname->setVisible(false);
    ui->errorregister->setVisible(false);
    ui->repasserror->setVisible(false);
    ui->groupBox_speciality->setVisible(false);
    ui->time->setVisible(false);
    ui->days->setVisible(false);

    QPixmap backgroundImage(":/Images/download.jpg");

    // Set the background image
    QBrush backgroundBrush(backgroundImage);
    QPalette palette = this->palette();
    palette.setBrush(QPalette::Window, backgroundBrush);
    this->setPalette(palette);
}

registering::~registering()
{
    delete ui;
}

void registering::on_doc_clicked()
{
    ui->days->setVisible(true);
    ui->time->setVisible(true);
    ui->groupBox_speciality->setVisible(true);

}


void registering::on_nurse_clicked()
{
    ui->days->setVisible(true);
    ui->time->setVisible(true);
    ui->groupBox_speciality->setVisible(false);

}


void registering::on_admin_clicked()
{
    ui->groupBox_speciality->setVisible(false);
    ui->time->setVisible(false);
    ui->days->setVisible(false);
}


void registering::on_patient_clicked()
{
    ui->groupBox_speciality->setVisible(false);
    ui->time->setVisible(false);
    ui->days->setVisible(false);
}

void registering::on_register_2_clicked()
{
    ui->errorname->setVisible(false);
    ui->errorregister->setVisible(false);
    ui->repasserror->setVisible(false);

    QString name= ui->nameedit->text();
    for (int i=0;i<patients.size();i++)
    {
        if (name==patients[i].username)
            ui->errorname->setVisible(true);
    }
    for (int i=0;i<admins.size();i++)
    {
        if (name==admins[i].username)
            ui->errorname->setVisible(true);
    }
    for (int i=0;i<doctors.size();i++)
    {
        if (name==doctors[i].username)
            ui->errorname->setVisible(true);
    }
    for (int i=0;i<nurses.size();i++)
    {
        if (name==nurses[i].username)
            ui->errorname->setVisible(true);
    }

    int age=0;
    if (ui->ageedit->text()!="")
    {
    age =ui->ageedit->text().toInt();
    }
    QString gender;
    if (ui->female->isChecked())
        gender="female";
    else if(ui->male->isChecked())
        gender="male";

    QString role;
    if (ui->patient->isChecked())
        role="patient";
    else if(ui->admin->isChecked())
        role="admin";
    else if (ui->doc->isChecked())
        role="doctor";
    else if (ui->nurse->isChecked())
        role="nurse";

    QString pass;
    if (ui->repass->text()!=ui->passedit->text())
        ui->repasserror->setVisible(true);
    else
        pass=ui->passedit->text();


    QVector<QString> dd;
    if (ui->checkBox->isChecked())
        dd.push_back(ui->checkBox->text());
    if (ui->checkBox_2->isChecked())
        dd.push_back(ui->checkBox_2->text());
    if (ui->checkBox_3->isChecked())
        dd.push_back(ui->checkBox_3->text());
    if (ui->checkBox_4->isChecked())
        dd.push_back(ui->checkBox_4->text());
    if (ui->checkBox_6->isChecked())
        dd.push_back(ui->checkBox_6->text());
    if (ui->checkBox_7->isChecked())
        dd.push_back(ui->checkBox_7->text());

    int st=0;
    if (ui->fromedit->text()!=""){
        st=ui->fromedit->text().toInt();
    }
    int e=0;
    if (ui->toedit->text()!=""){
        e=ui->toedit->text().toInt();

    ///Nutrition,OG,IM,Ophthalmology,Dermatology

    QString spec="";
    if (ui->radioButton_Nutrition->isChecked())
        spec="Nutrition";
    else if (ui->radioButton_Dermatology->isChecked())
        spec="Dermatology";
    else if (ui->radioButton_OG->isChecked())
        spec="OG";
    else if (ui->radioButton_Ophthalmology->isChecked())
        spec="Ophthalmology";
    else if (ui->radioButton_internalmedicine->isChecked())
        spec="IM";

    bool drcheck=false;
    if (spec!=""&&st!=0&&e!=0&&!dd.empty())
        drcheck=true;
    bool nursecheck=false;
    if (st!=0&&e!=0&&!dd.empty())
        nursecheck=true;

    if (name==""||pass==""||gender==""||age==0||role=="")
    {

        if (ui->time->isVisible())
            if (st==0 || e==0)
                ui->errorregister->setVisible(true);
        if (ui->days->isVisible()==true)
            if (dd.empty())
                ui->errorregister->setVisible(true);
        if (ui->groupBox_speciality->isVisible()==true)
            if (spec=="")
                ui->errorregister->setVisible(true);

        ui->errorregister->setVisible(true);
    }


    if (!ui->repasserror->isVisible()&&!ui->errorregister->isVisible()&&!ui->errorname->isVisible())
    {

        if (role=="admin")
        {
            admins.push_back(admin(name,pass,gender,age));
        }
        else if (role=="patient")
        {
            patients.push_back(patient(name,pass,age,gender));
        }
        else if (role=="doctor")
        {
            if (drcheck==false){
                ui->errorregister->setVisible(true);
                return;
            }
            doctors.push_back(drclass(name,pass,spec,gender,age,st,e,dd));
        }
        else if (role=="nurse")
        {
            if (nursecheck==false){
                ui->errorregister->setVisible(true);
                return;
            }
            nurses.push_back(nurse(name,pass,gender,age,st,e,dd));
        }
        hide();
        MainWindow *win=new MainWindow(this);
        win->show();

    }
}

}
