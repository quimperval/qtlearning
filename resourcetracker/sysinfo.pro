QT       += core gui charts

CONFIG += c++14

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = sysinfo

TEMPLATE = app

SOURCES += \
    cpuwidget.cpp \
    main.cpp \
    MainWindow.cpp \
    SysInfo.cpp \
    sysinfowidget.cpp

HEADERS += \
    MainWindow.h \
    SysInfo.h \
    cpuwidget.h \
    sysinfowidget.h

windows {
        SOURCES +=  SysInfoWindowsImpl.cpp
        HEADERS +=  SysInfoWindowsImpl.h
}

linux {
        SOURCES +=  SysInfoLinuxImpl.cpp
        HEADERS +=  SysInfoLinuxImpl.h
}

FORMS += \
    MainWindow.ui
    

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
