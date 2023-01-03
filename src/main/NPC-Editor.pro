QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    errors/erralreadyrunning.cpp \
    errors/errsidebarstatus.cpp \
    main.cpp \
    mainwindow.cpp \
    plugins/npcGiftEditor/npcgifteditor.cpp

HEADERS += \
    errors/erralreadyrunning.h \
    errors/errsidebarstatus.h \
    mainwindow.h \
    plugins/npcGiftEditor/npcgifteditor.h

FORMS += \
    errors/erralreadyrunning.ui \
    errors/errsidebarstatus.ui \
    mainwindow.ui \
    plugins/npcGiftEditor/npcgifteditor.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
TRANSLATIONS    +=\  interface_en.ts
