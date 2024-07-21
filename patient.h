#ifndef PATIENT_H
#define PATIENT_H
#include <QString>
#include <QFile>
#include <QMap>
class patient
{
public:
    patient();
     patient(QString n, QString p, int a, QString g);
    QString username;
    QString pass;
    //QString name; // Example: Name of the patient
    QString bloodType; // Example: Blood type of the patient
    QString chronicDiseases; // Example: Chronic diseases of the patient
    int age;
    QString gender;
    // Add more fields as needed
    QMap<QString,QString>  appointments;

};

#endif // PATIENT_H
