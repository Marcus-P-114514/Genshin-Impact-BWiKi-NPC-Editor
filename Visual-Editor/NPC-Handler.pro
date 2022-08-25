QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    npc_gift_option.cpp \
    npc_store_multi_exchange.cpp

HEADERS += \
    mainwindow.h \
    npc_gift_option.h \
    npc_store_multi_exchange.h

FORMS += \
    mainwindow.ui \
    npc_gift_option.ui \
    npc_store_multi_exchange.ui

TRANSLATIONS += \
    NPC-Handler_en_US.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
