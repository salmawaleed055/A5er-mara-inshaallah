#include "users.h"

#include <QString>
#include <QVector>
#include "patient.h"
#include "admin.h"
#include "drclass.h"
#include "nurse.h"

QVector<patient> patients={patient("Ali","1234",22,"male"),patient("Amr","4321",43,"male")};
QVector<admin> admins={admin("Saly","ssss","female",21),admin("Dina","dddd","female",32)};
QVector<drclass> doctors={drclass("Ayman","aaaa","Nutrition","male",50,14,20,{"Sunday","Thurseday"}),
                            drclass("Mourad","mmmm","OG","male",44,6,10,{"Monday","Wednesday"}),
                            drclass("Dalia","dall","Ophthalmology","female",44,6,10,{"Saturday","Wednesday"}),
                            drclass("Sayed","sayy","Dermatology","male",44,10,18,{"Monday","Wednesday"}),
                            drclass("Mariam","marr","IM","female",44,12,23,{"Monday","Saturday"}),
                            drclass("Diana","diaa","Ophthalmology","female",44,2,8,{"Monday","Wednesday"})};
//Nutrition,OG,IM,Ophthalmology,Dermatology
QVector<nurse> nurses={nurse("Suzi","szsz","female",20,12,23,{"Sunday","Thurseday"}),
                         nurse("Amgad","amam","male",23,6,10,{"Monday","Wednesday"}),
                         nurse("Hania","hanh","female",28,1,12,{"Tuesday"})};
QVector<drclass*> Nutrition;
QVector<drclass*> OG;
QVector<drclass*> IM;
QVector<drclass*>Derm;
QVector<drclass*> oph;

users::users() {}
//QString n, QString p, QString s , QString g, int a,int st,int e,QVector<QString> d
