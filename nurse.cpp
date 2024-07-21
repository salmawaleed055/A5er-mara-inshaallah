#include "nurse.h"

nurse::nurse() {}
nurse::nurse(QString n, QString p, QString g, int a,int st,int e,QVector<QString> d){
    username = n;
    pass =p;
    gender =g;
    age = a;
    starttime=st;
    endtime=e;
    days=d;
}
