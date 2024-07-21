#ifndef PATIENTMANAGMENTWINDOW_H
#define PATIENTMANAGMENTWINDOW_H

#include "patient.h"
#include <QDialog>
#include <QFile>
#include <QMap>

namespace Ui {
class PatientManagmentWindow;
}

class PatientManagmentWindow : public QDialog
{
    Q_OBJECT

public:
    explicit PatientManagmentWindow(QWidget *parent = nullptr,QString patname="");
    ~PatientManagmentWindow();
     void setUsername(const QString &username);
     //void setPatient(const patient &patient);
     //QMap<QString, QString> appointments;
    // void addToAppointments(const QString &slot);
     void updateComboBoxes();
     //void pushElement(const QString &key, const QString &value);

private slots:
    void on_pushButtonBook_clicked();

    void on_pushButtonReschedule_clicked();

    void on_pushButtonCancel_clicked();

    void on_pushButtonChat_clicked();

    void on_pushButtonMedical_Record_clicked();

    void on_pushButtonSubmit_clicked();



    void on_pushButton_clicked();

    void on_pushButtonMedical_Record_2_clicked();


private:
    Ui::PatientManagmentWindow *ui;
    QString username1;
    patient* currentPatient;
    bool submit = false; // Add this flag
   // QMap<QString, QString> appointments;

};

#endif // PATIENTMANAGMENTWINDOW_H
