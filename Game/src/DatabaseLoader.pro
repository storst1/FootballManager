QT       += core gui network sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    club.cpp \
    data_collector.cpp \
    database.cpp \
    json_parser.cpp \
    json_parser_player.cpp \
    json_parser_squad.cpp \
    league.cpp \
    main.cpp \
    mainwindow.cpp \
    network_manager.cpp \
    player.cpp \
    request_buffer.cpp

HEADERS += \
    club.h \
    database.h \
    json_parser.h \
    json_parser_player.h \
    json_parser_squad.h \
    league.h \
    mainwindow.h \
    network_manager.h \
    player.h \
    request_buffer.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
