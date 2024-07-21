
#ifndef USERS_H
#define USERS_H
#include <QString>
#include <QVector>
#include "patient.h"
#include "admin.h"
#include "drclass.h"
#include "nurse.h"

extern QVector<patient> patients;
extern QVector<admin> admins;
extern QVector<drclass> doctors;
extern QVector<drclass*> Nutrition;
extern QVector<drclass*> OG;
extern QVector<drclass*> oph;
extern QVector<drclass*> IM;
extern QVector<drclass*> Derm;
extern QVector<nurse> nurses;
class users
{
public:
    users();
};

#endif // USERS_H
