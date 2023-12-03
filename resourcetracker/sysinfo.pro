QT       += core gui

CONFIG += c++14

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = sysinfo

TEMPLATE = app

SOURCES += \
    main.cpp \
    MainWindow.cpp \
    SysInfo.cpp

HEADERS += \
    MainWindow.h \
    SysInfo.h

windows {
        SOURCES +=  SysInfoWindowsImpl.cpp
        HEADERS +=  SysInfoWindowsImpl.h
}

FORMS += \
    MainWindow.ui
    

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
