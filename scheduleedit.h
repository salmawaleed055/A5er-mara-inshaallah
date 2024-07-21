#ifndef SCHEDULEEDIT_H
#define SCHEDULEEDIT_H
#include "drclass.h"
#include "doctor.h"
#include "nurse.h"
#include <QDialog>

namespace Ui {
class scheduleedit;
}

class scheduleedit : public QDialog
{
    Q_OBJECT

public:
    explicit scheduleedit(QWidget *parent = nullptr, QString drname = "");
    ~scheduleedit();


private slots:
    void on_pushButton_submit_clicked();

private:
    Ui::scheduleedit *ui;
    drclass* d;
    nurse*n;
};

#endif // SCHEDULEEDIT_H
