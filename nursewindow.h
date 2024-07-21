#ifndef NURSEWINDOW_H
#define NURSEWINDOW_H

#include <QDialog>
#include "nurse.h"

namespace Ui {
class nursewindow;
}

class nursewindow : public QDialog
{
    Q_OBJECT

public:
    explicit nursewindow(QWidget *parent = nullptr,QString n ="");
    ~nursewindow();
    QString getAssignmentString(nurse& nuu);

private slots:
    void on_pushButton_profile_clicked();

    void on_pushButton_Schedule_clicked();

    void on_pushButton_Assignment_clicked();

    void on_pushButton_clicked();

    void on_pushButton_editschedule_clicked();

private:
    Ui::nursewindow *ui;
    nurse *nur;
};

#endif // NURSEWINDOW_H
