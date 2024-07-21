QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    admin.cpp \
    adminwindow.cpp \
    bookappointmentwindow.cpp \
    cancelappointmentwindow.cpp \
    chat.cpp \
    doctor.cpp \
    drclass.cpp \
    main.cpp \
    mainwindow.cpp \
    nurse.cpp \
    nursewindow.cpp \
    patient.cpp \
    patientmanagmentwindow.cpp \
    registering.cpp \
    rescheduleappointmentwindow.cpp \
    scheduleedit.cpp \
    users.cpp

HEADERS += \
    admin.h \
    adminwindow.h \
    bookappointmentwindow.h \
    cancelappointmentwindow.h \
    chat.h \
    doctor.h \
    drclass.h \
    mainwindow.h \
    nurse.h \
    nursewindow.h \
    patient.h \
    patientmanagmentwindow.h \
    registering.h \
    rescheduleappointmentwindow.h \
    scheduleedit.h \
    users.h

FORMS += \
    adminwindow.ui \
    bookappointmentwindow.ui \
    cancelappointmentwindow.ui \
    chat.ui \
    doctor.ui \
    mainwindow.ui \
    nursewindow.ui \
    patientmanagmentwindow.ui \
    registering.ui \
    rescheduleappointmentwindow.ui \
    scheduleedit.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Images.qrc
