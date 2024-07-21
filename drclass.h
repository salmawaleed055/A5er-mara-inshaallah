#ifndef DRCLASS_H
#define DRCLASS_H
#include <QString>
#include <QFile>
#include <QVector>

class drclass
{
public:
    drclass();
    drclass(QString n, QString p, QString s , QString g, int a,int ,int e,QVector<QString>);
    QString username;
    QString pass;
    QString specialization; // Example: Blood type of the patient
    /////specialization is only one of these five with the same writing as here (Nutrition,OG,IM,Ophthalmology,Dermatology)
    QString gender;
    int age;
    //QVector<QString> patientschedule;
    QVector<QString> days;
    QVector<QString> dpatients;
    int starttime;
    int endtime;
    bool operator==(const drclass& other);
};

#endif // DRCLASS_H
