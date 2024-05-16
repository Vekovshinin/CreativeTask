QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    fifthflor.cpp \
    firstflor.cpp \
    fourthflor.cpp \
    hotel.cpp \
    infoaboutpeople.cpp \
    main.cpp \
    mainwindow.cpp \
    n405.cpp \
    secondflor.cpp \
    secondwindow.cpp \
    thirdflor.cpp \
    vipone.cpp

HEADERS += \
    fifthflor.h \
    firstflor.h \
    fourthflor.h \
    hotel.h \
    infoaboutpeople.h \
    mainwindow.h \
    n405.h \
    secondflor.h \
    secondwindow.h \
    thirdflor.h \
    vipone.h

FORMS += \
    fifthflor.ui \
    firstflor.ui \
    fourthflor.ui \
    hotel.ui \
    infoaboutpeople.ui \
    mainwindow.ui \
    n405.ui \
    secondflor.ui \
    secondwindow.ui \
    thirdflor.ui \
    vipone.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
