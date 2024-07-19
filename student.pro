QT       += core gui
QT+=sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    LogWindow.cpp \
    graph.cpp \
    main.cpp \
    mainwindow.cpp \
    manager.cpp \
    operation.cpp \
    queryresult.cpp \
    student.cpp \
    subjectwindow.cpp \
    widget.cpp \
    window01.cpp \
    window02.cpp \
    window03.cpp

HEADERS += \
    LogWindow.h \
    courseinfo.h \
    graph.h \
    mainwindow.h \
    manager.h \
    operation.h \
    queryresult.h \
    student.h \
    subjectwindow.h \
    widget.h \
    window01.h \
    window02.h \
    window03.h

FORMS += \
    LogWindow.ui \
    mainwindow.ui \
    queryresult.ui \
    subjectwindow.ui \
    widget.ui \
    window01.ui \
    window02.ui \
    window03.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
  # qimage.qrc \
    # qimage.qrc \
    #  qimage.qrc \
   #  qimage.qrc \
    res.qrc
