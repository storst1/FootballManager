QT       += core gui network sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    api/api_club.cpp \
    api/api_league.cpp \
    api/api_player.cpp \
    database/database.cpp \
    database/database_real_data.cpp \
    database/database_skill_converter.cpp \
    game/data/club.cpp \
    game/data/coach.cpp \
    game/data/confederation.cpp \
    game/data/cup.cpp \
    game/data/federation.cpp \
    game/data/fifa.cpp \
    game/data/league.cpp \
    game/data/national_team.cpp \
    game/data/player.cpp \
    game/data/team.cpp \
    json/json_parser.cpp \
    json/json_parser_player.cpp \
    json/json_parser_squad.cpp \
    main/data_collector.cpp \
    main/main.cpp \
    main/mainwindow.cpp \
    network/network_manager.cpp \
    network/request_buffer.cpp

HEADERS += \
    api/api_club.h \
    api/api_league.h \
    api/api_player.h \
    database/database.h \
    database/database_real_data.h \
    database/database_skill_converter.h \
    game/data/club.h \
    game/data/coach.h \
    game/data/confederation.h \
    game/data/cup.h \
    game/data/federation.h \
    game/data/fifa.h \
    game/data/league.h \
    game/data/national_team.h \
    game/data/player.h \
    game/data/team.h \
    json/json_parser.h \
    json/json_parser_player.h \
    json/json_parser_squad.h \
    main/mainwindow.h \
    network/network_manager.h \
    network/request_buffer.h

FORMS += \
    main/mainwindow.ui \

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target