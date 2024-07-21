#include "chat.h"
#include "ui_chat.h"

chat::chat(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::chat)
{
    ui->setupUi(this);
    QPixmap backgroundImage(":/Images/download.jpg");

    // Set the background image
    QBrush backgroundBrush(backgroundImage);
    QPalette palette = this->palette();
    palette.setBrush(QPalette::Window, backgroundBrush);
    this->setPalette(palette);
    ui->labelsubmitclicked->setVisible(false);
}

chat::~chat()
{
    delete ui;
}

void chat::on_pushButtonsubmit_clicked()
{
    ui->plainTextEdit_Chat->setPlainText("");
    ui->labelsubmitclicked->setVisible(true);
    //ui->labelsubmitclicked->setText("<font color='blue'>Your message is sent. Expect a call very soon</font>");

}

