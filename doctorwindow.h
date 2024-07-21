#ifndef DOCTORWINDOW_H
#define DOCTORWINDOW_H

#include <QDialog>

namespace Ui {
class doctorwindow;
}

class doctorwindow : public QDialog
{
    Q_OBJECT

public:
    explicit doctorwindow(QWidget *parent = nullptr);
    ~doctorwindow();

private:
    Ui::doctorwindow *ui;
};

#endif // DOCTORWINDOW_H
