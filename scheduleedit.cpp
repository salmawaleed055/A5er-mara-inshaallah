#include "scheduleedit.h"
#include "ui_scheduleedit.h"
#include "drclass.h"
#include "users.h"
#include "doctor.h"
#include "nursewindow.h"
int drornurse =0;
scheduleedit::scheduleedit(QWidget *parent, QString drname)
    : QDialog(parent)
    , ui(new Ui::scheduleedit)
{
    ui->setupUi(this);
    QPixmap backgroundImage(":/Images/download.jpg");

    // Set the background image
    QBrush backgroundBrush(backgroundImage);
    QPalette palette = this->palette();
    palette.setBrush(QPalette::Window, backgroundBrush);
    this->setPalette(palette);

    ui->label_error->setVisible (false);
    ui->plainTextEdit->setVisible(false);
    for (int i=0;i<doctors.size();i++)
    {
        if (doctors[i].username==drname){
            d=&doctors[i];
            drornurse = 1;
            break;
        }
    }
    for (int i=0;i<nurses.size();i++)
    {
        if (nurses[i].username==drname){
            n=&nurses[i];
            drornurse = 2;
            break;
        }
    }
    if (drornurse==1){
        if (!d->dpatients.empty()){
            ui->plainTextEdit->setVisible(true);
        }
    }
}

scheduleedit::~scheduleedit()
{
    delete ui;

}

void scheduleedit::on_pushButton_submit_clicked()
{
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
    }
    if (st==0 || e==0 || dd.empty())
        ui->label_error->setVisible(true);

    else{
        if(drornurse == 1) {
        d->days.clear();
        d->days = dd; // Push back the new values of date in the vector of days
        d->starttime = st;
        d->endtime = e;


        hide();
        doctor* ddd = new doctor(this, d->username);
        ddd->show();
        }

        else if(drornurse == 2){
            n->days.clear();
            n->days = dd; // Push back the new values of date in the vector of days
            n->starttime = st;
            n->endtime = e;


            hide();
            nursewindow* ddd = new nursewindow (this, n->username);
            ddd->show();
        }
    }

}

