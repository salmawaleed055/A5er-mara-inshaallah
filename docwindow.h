#ifndef DOCWINDOW_H
#define DOCWINDOW_H

#include <QDialog>
#include "drclass.h"
namespace Ui {
class docwindow;
}

class docwindow : public QDialog
{
    Q_OBJECT

public:
    explicit docwindow(QWidget *parent = nullptr, drclass d = drclass("","","","",0,0,0,{}));
    ~docwindow();

private slots:
    void on_pushButton_profile_clicked();

private:
    Ui::docwindow *ui;
};

#endif // DOCWINDOW_H
