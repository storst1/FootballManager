QT += core gui network sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

SOURCES += \
    api/api_club.cpp \
    api/api_keys.cpp \
    api/api_league.cpp \
    api/api_player.cpp \
    database/database.cpp \
    database/database_api_keys.cpp \
    database/database_dynamic_data.cpp \
    database/database_real_data.cpp \
    database/database_skill_converter.cpp \
    game/data/coach.cpp \
    game/data/confederation.cpp \
    game/data/country_map.cpp \
    game/data/cup.cpp \
    game/data/federation.cpp \
    game/data/fifa.cpp \
    game/data/game_data.cpp \
    game/data/league.cpp \
    game/data/player.cpp \
    game/data/player_position.cpp \
    game/data/stadium.cpp \
    game/data/table.cpp \
    game/data/team.cpp \
    game/time/date.cpp \
    game/user/user.cpp \
    json/json_parser.cpp \
    json/json_parser_club.cpp \
    json/json_parser_player.cpp \
    json/json_parser_squad.cpp \
    layouts/new_game_scene.cpp \
    layouts/settings_scene.cpp \
    layouts/starting_scene.cpp \
    main/data_collector.cpp \
    main/main.cpp \
    main/mainwindow.cpp \
    network/network_manager.cpp \
    network/request_buffer.cpp

HEADERS += \
    api/api_club.h \
    api/api_keys.h \
    api/api_league.h \
    api/api_player.h \
    database/database.h \
    database/database_api_keys.h \
    database/database_dynamic_data.h \
    database/database_real_data.h \
    database/database_skill_converter.h \
    game/data/coach.h \
    game/data/confederation.h \
    game/data/country_map.h \
    game/data/cup.h \
    game/data/data_defs.h \
    game/data/federation.h \
    game/data/fifa.h \
    game/data/game_data.h \
    game/data/league.h \
    game/data/player.h \
    game/data/player_position.h \
    game/data/stadium.h \
    game/data/table.h \
    game/data/team.h \
    game/time/date.h \
    game/user/user.h \
    json/json_parser.h \
    json/json_parser_club.h \
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

RESOURCES += \
    ../../Resources/backgrounds.qrc \
    ../../Resources/logos.qrc
