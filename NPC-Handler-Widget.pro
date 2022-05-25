QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    basic_info.cpp \
    main.cpp \
    mainwindow.cpp \
    store.cpp

HEADERS += \
    basic_info.h \
    mainwindow.h \
    store.h

FORMS += \
    basic_info.ui \
    mainwindow.ui \
    store.ui

TRANSLATIONS += \
    NPC-Handler-Widget_zh_CN.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
