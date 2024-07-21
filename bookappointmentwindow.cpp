#include "bookappointmentwindow.h"
#include "ui_bookappointmentwindow.h"
#include <qlist.h>
#include <QListWidgetItem>
#include <patient.h>
#include <patientmanagmentwindow.h>//>
#include "users.h"
#include "patient.h"
#include "drclass.h"
#include "doctor.h"
#include <QDebug>
#include "scheduleedit.h"

BookAppointmentWindow::BookAppointmentWindow(QWidget *parent,QString patname)
    : QDialog(parent)
    , ui(new Ui::BookAppointmentWindow)
{
    ui->setupUi(this);
    for (int i=0;i<patients.size();i++)
    {
        if (patients[i].username==patname){
            currpat=&patients[i];
            break;
        }
    }
    ui->labelERROR->setVisible(false);
    QPixmap backgroundImage(":/Images/download.jpg");

    // Set the background image
    QBrush backgroundBrush(backgroundImage);
    QPalette palette = this->palette();
    palette.setBrush(QPalette::Window, backgroundBrush);
    this->setPalette(palette);

    connect(ui->radioButton_Nutrition, &QRadioButton::clicked, this, &BookAppointmentWindow::on_radioButton_Nutrition_clicked);
    connect(ui->radioButton_OG, &QRadioButton::clicked, this, &BookAppointmentWindow::on_radioButton_OG_clicked);
    connect(ui->radioButton_Ophthalmology, &QRadioButton::clicked, this, &BookAppointmentWindow::on_radioButton_Ophthalmology_clicked);
    connect(ui->radioButton_internalmedicine, &QRadioButton::clicked, this, &BookAppointmentWindow::on_radioButton_internalmedicine_clicked);
    connect(ui->radioButton_Dermatology, &QRadioButton::clicked, this, &BookAppointmentWindow::on_radioButton_Dermatology_clicked);
    connect(ui->slotsListView, &QListWidget::itemClicked, this, &BookAppointmentWindow::on_slotsListView_itemClicked);
   // connect(ui->pushButtonSubmit, &QPushButton::clicked, this, &BookAppointmentWindow::on_pushButtonSubmit_clicked);
}

BookAppointmentWindow::~BookAppointmentWindow()
{
    delete ui;
}
void BookAppointmentWindow::clearSlotsList()
{
    ui->slotsListView->clear();
}
void BookAppointmentWindow::addSlotToList(const QString &slot)
{
    QListWidgetItem *item = new QListWidgetItem(slot);
    ui->slotsListView->addItem(item);
}


// void BookAppointmentWindow::pushElement(const QString &key, const QString &value) {
//     // Perform actions to add element to map or wherever it's stored
//     // For example:
//     //currentPatient.appointments.insert(key, value);

//     // Emit the signal to notify other parts of the application
//     emit elementAdded(key, value);
// }
void BookAppointmentWindow::on_radioButton_Nutrition_clicked()
{
   ui->label_Available_slots->setText("Available slots and doctors are:");
    clearSlotsList();
   for (int i=0;i<Nutrition.size();i++)
   {
        for (int j=0;j<Nutrition[i]->days.size();j++)
       {
           addSlotToList(Nutrition[i]->username+" on "+Nutrition[i]->days[j]+" from "+QString::number(Nutrition[i]->starttime)+" to "+QString::number(Nutrition[i]->endtime));
       }
   }
}


void BookAppointmentWindow::on_radioButton_OG_clicked()
{
    ui->label_Available_slots->setText("Available slots and doctors are:");
    clearSlotsList();
    for (int i=0;i<OG.size();i++)
    {
        for (int j=0;j<OG[i]->days.size();j++)
        {
            addSlotToList(OG[i]->username+" on "+OG[i]->days[j]+" from "+QString::number(OG[i]->starttime)+" to "+QString::number(OG[i]->endtime));
        }
    }
}


void BookAppointmentWindow::on_radioButton_Ophthalmology_clicked()
{
    ui->label_Available_slots->setText("Available slots and doctors are:");
    clearSlotsList();
    for (int i=0;i<oph.size();i++)
    {
        for (int j=0;j<oph[i]->days.size();j++)
        {
            addSlotToList(oph[i]->username+" on "+oph[i]->days[j]+" from "+QString::number(oph[i]->starttime)+" to "+QString::number(oph[i]->endtime));
        }
    }
}


void BookAppointmentWindow::on_radioButton_internalmedicine_clicked()
{
    ui->label_Available_slots->setText("Available slots and doctors are:");
    clearSlotsList();
    for (int i=0;i<IM.size();i++)
    {
        for (int j=0;j<IM[i]->days.size();j++)
        {
            addSlotToList(IM[i]->username+" on "+IM[i]->days[j]+" from "+QString::number(IM[i]->starttime)+" to "+QString::number(IM[i]->endtime));
        }
    }
}


void BookAppointmentWindow::on_radioButton_Dermatology_clicked()
{
    ui->label_Available_slots->setText("Available slots and doctors are:");
    clearSlotsList();
    for (int i=0;i<Derm.size();i++)
    {
        for (int j=0;j<Derm[i]->days.size();j++)
        {
            addSlotToList(Derm[i]->username+" on "+Derm[i]->days[j]+" from "+QString::number(Derm[i]->starttime)+" to "+QString::number(Derm[i]->endtime));
        }
    }
}


void BookAppointmentWindow::on_slotsListView_itemClicked(QListWidgetItem *item)
{
    if (!item) {
        return;
    }

        QString selectedSlot = item->text();
        QString selectedSpecialty;

        if (ui->radioButton_Nutrition->isChecked()) {
            selectedSpecialty = "Nutrition";
        } else if (ui->radioButton_OG->isChecked()) {
            selectedSpecialty = "OG";
        } else if (ui->radioButton_Ophthalmology->isChecked()) {
            selectedSpecialty = "Ophthalmology";
        } else if (ui->radioButton_internalmedicine->isChecked()) {
            selectedSpecialty = "IM";
        } else if (ui->radioButton_Dermatology->isChecked()) {
            selectedSpecialty = "Dermatology";
        }


        if (!selectedSpecialty.isEmpty()) {

            currpat->appointments.insert(selectedSpecialty,selectedSlot);

        }
}

void BookAppointmentWindow::on_pushButtonSubmit_clicked()     ///not handeled yet
{
    ui->labelERROR->setVisible(false);
    //submitClicked = true;
    //int i= ui->slotsListView->currentIndex();
    QString selectedSlot;
    QListWidgetItem *currentItem = ui->slotsListView->currentItem();
    if(currentItem){
        selectedSlot = currentItem->text();
    }


    else{
        qDebug() << "No item selected in slotsListView.";
        ui->labelERROR->setVisible(true);
    }
    if (!ui->labelERROR->isVisible())
    {
    hide();
    PatientManagmentWindow* win=new PatientManagmentWindow(this,currpat->username);
    win->show();
    }
}

