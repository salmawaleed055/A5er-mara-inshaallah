#ifndef RESCHEDULEAPPOINTMENTWINDOW_H
#define RESCHEDULEAPPOINTMENTWINDOW_H

#include <QDialog>

namespace Ui {
class RescheduleAppointmentWindow;
}

class RescheduleAppointmentWindow : public QDialog
{
    Q_OBJECT

public:
    explicit RescheduleAppointmentWindow(QWidget *parent = nullptr);
    ~RescheduleAppointmentWindow();

private:
    Ui::RescheduleAppointmentWindow *ui;
};

#endif // RESCHEDULEAPPOINTMENTWINDOW_H
