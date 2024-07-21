#ifndef DOCTOR_H
#define DOCTOR_H
#include "drclass.h"
#include <QDialog>
#include "bookappointmentwindow.h"
#include "patientmanagmentwindow.h"

namespace Ui {
class doctor;
}

class doctor : public QDialog
{
    Q_OBJECT

public:
    explicit doctor(QWidget *parent = nullptr, QString docname="");
    ~doctor();
    QString getAssignmentString(drclass& doc);
    //void updateAssignments(const patient& pat);
private slots:
    void on_pushButton_profile_clicked();

    void on_pushButton_profile_2_clicked();

    void on_pushButton_schedule_clicked();

    void on_pushButton_clicked();

    void on_pushButton_editschedule_clicked();

private:
    Ui::doctor *ui;
    drclass* currdoc;
};

#endif // DOCTOR_H
