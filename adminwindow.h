#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H
// #include "doctor.h"
// #include "nurse.h"
#include <QDialog>
#include "admin.h"

namespace Ui {
class adminwindow;
}

class adminwindow : public QDialog
{
    Q_OBJECT

public:
    explicit adminwindow(QWidget *parent = nullptr,admin ad=admin("","","",0));
    ~adminwindow();

private slots:
    void on_pat_clicked();

    void on_staff_clicked();

    void on_submit_clicked();

    void on_doc_clicked();

    void on_nurse_clicked();

    void on_pushButton_clicked();

private:
    Ui::adminwindow *ui;
    // QVector<doctor> doctors;
    // QVector<nurse> nurses;
};

#endif // ADMINWINDOW_H
