#include "docwindow.h"
#include "ui_docwindow.h"

docwindow::docwindow(QWidget *parent, drclass d)
    : QDialog(parent)
    , ui(new Ui::docwindow)
{
    ui->setupUi(this);
}

docwindow::~docwindow()
{
    delete ui;
}

void docwindow::on_pushButton_profile_clicked()
{
    QString prof="Name: "+ d.username;
}

