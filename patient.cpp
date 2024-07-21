#include "patient.h"


patient::patient() {
    // Initialize default values or leave empty, depending on your needs
}
patient::patient(QString n, QString p, int a, QString g){
    username=n;
    age=a;
    pass=p;
    gender=g;
}

