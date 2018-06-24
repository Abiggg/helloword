#-------------------------------------------------
#
# Project created by QtCreator 2018-05-09T02:21:47
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = helloworld
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
    mainwindow.cpp \
    stdqtcvfile.cpp \
    stdimagebasic.cpp \
    mathfun.cpp \
    winbeatifyphoto.cpp \
    winaiphoto.cpp \
    datast.cpp \
    threadfromqthread.cpp \
    mathlib.cpp \
    bpnetwork.cpp \
    stdfile.cpp \
    lenet.cpp

HEADERS += \
    mainwindow.h \
    stddatatype.h \
    stdqtcvfile.h \
    stdimagebasic.h \
    mathfun.h \
    winbeatifyphoto.h \
    winaiphoto.h \
    datast.h \
    threadfromqthread.h \
    mathlib.h \
    bpnetwork.h \
    stdfile.h \
    lenet.h

FORMS += \
    mainwindow.ui \
    winbeatifyphoto.ui \
    winaiphoto.ui

DISTFILES +=

INCLUDEPATH += /usr/local/include/opencv/
/usr/local/include/opencv2/
/usr/local/include

LIBS += -L/usr/local/lib -lopencv_core\
-lopencv_imgproc\
-lopencv_highgui\
-lopencv_ml\
-lopencv_video\
-lopencv_features2d\
-lopencv_calib3d\
-lopencv_objdetect\
-lopencv_flann\
-lopencv_imgcodecs\
-lopencv_shape\
-lopencv_videoio

RESOURCES += \
    defaultphoto.qrc


