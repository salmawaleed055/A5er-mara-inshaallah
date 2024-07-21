#include "cancelappointmentwindow.h"
#include "ui_cancelappointmentwindow.h"

CancelAppointmentWindow::CancelAppointmentWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CancelAppointmentWindow)
{
    ui->setupUi(this);
}

CancelAppointmentWindow::~CancelAppointmentWindow()
{
    delete ui;
}
