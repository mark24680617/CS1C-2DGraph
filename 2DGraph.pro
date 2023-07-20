QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    contact.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    line.cpp \
    polyline.cpp \
    polygon.cpp \
    Rectangle.cpp \
    Ellipse.cpp \
    Text.cpp \

HEADERS += \
    contact.h \
    login.h \
    mainwindow.h \
    shape.h \
    vector.h \
    line.h \
    polyline.h \
    polygon.h \
    Rectangle.h \
    Ellipse.h \
    Text.h \

FORMS += \
    contact.ui \
    login.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resources.qrc

