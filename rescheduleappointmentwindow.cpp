#include "rescheduleappointmentwindow.h"
#include "ui_rescheduleappointmentwindow.h"

RescheduleAppointmentWindow::RescheduleAppointmentWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::RescheduleAppointmentWindow)
{
    ui->setupUi(this);
    QPixmap backgroundImage(":/Images/download.jpg");

    QBrush backgroundBrush(backgroundImage);
    QPalette palette = this->palette();
    palette.setBrush(QPalette::Window, backgroundBrush);
    this->setPalette(palette);
}

RescheduleAppointmentWindow::~RescheduleAppointmentWindow()
{
    delete ui;
}
