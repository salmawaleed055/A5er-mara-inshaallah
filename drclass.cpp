#include "drclass.h"

drclass::drclass() {

}
drclass::drclass(QString n, QString p, QString s , QString g, int a,int st,int e,QVector<QString> d){
    username = n;
    pass =p;
    specialization =s;
    gender =g;
    age = a;
    starttime=st;
    endtime=e;
    days=d;
}
bool drclass::operator==(const drclass& other){
    return(username==other.username);
}
