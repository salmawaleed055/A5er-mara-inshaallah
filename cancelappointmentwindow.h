#ifndef CANCELAPPOINTMENTWINDOW_H
#define CANCELAPPOINTMENTWINDOW_H

#include <QDialog>

namespace Ui {
class CancelAppointmentWindow;
}

class CancelAppointmentWindow : public QDialog
{
    Q_OBJECT

public:
    explicit CancelAppointmentWindow(QWidget *parent = nullptr);
    ~CancelAppointmentWindow();

private:
    Ui::CancelAppointmentWindow *ui;
};

#endif // CANCELAPPOINTMENTWINDOW_H
