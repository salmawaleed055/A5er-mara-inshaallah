#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qlabel.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setpatapp(QMap<QString,QString> app,QString n);
private slots:
    void on_pushButtonLogin_clicked();

    void on_PushbuttonRegister_clicked();
    //void updateMap(const QString &key, const QString &value);
private:
    Ui::MainWindow *ui;
    QLabel *imageLabel;

};
#endif // MAINWINDOW_H
