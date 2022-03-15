QT       += core gui network sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    api_club.cpp \
    api_league.cpp \
    api_player.cpp \
    data_collector.cpp \
    database.cpp \
    database_real_data.cpp \
    database_skill_converter.cpp \
    json_parser.cpp \
    json_parser_player.cpp \
    json_parser_squad.cpp \
    main.cpp \
    mainwindow.cpp \
    network_manager.cpp \
    request_buffer.cpp

HEADERS += \
    api_club.h \
    api_league.h \
    api_player.h \
    database.h \
    database_real_data.h \
    database_skill_converter.h \
    json_parser.h \
    json_parser_player.h \
    json_parser_squad.h \
    mainwindow.h \
    network_manager.h \
    request_buffer.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
