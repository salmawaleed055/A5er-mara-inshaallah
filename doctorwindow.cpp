#include "doctorwindow.h"
#include "ui_doctorwindow.h"

doctorwindow::doctorwindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::doctorwindow)
{
    ui->setupUi(this);
}

doctorwindow::~doctorwindow()
{
    delete ui;
}
