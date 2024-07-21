#ifndef NURSE_H
#define NURSE_H
#include <QString>
#include <QVector>
class nurse
{
public:
    nurse();
    nurse(QString n, QString p, QString g, int a,int ,int e,QVector<QString>);
    QString username;
    QString pass;
    QString gender;
    int age;
    QVector<QString> days;
    int starttime;
    int endtime;
    QVector<QString> patients;

};

#endif // NURSE_H
