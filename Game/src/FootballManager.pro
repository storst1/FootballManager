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
    files/tmp_files.cpp \
    game/data/calendar.cpp \
    game/data/coach.cpp \
    game/data/competition.cpp \
    game/data/confederation.cpp \
    game/data/country_map.cpp \
    game/data/cup.cpp \
    game/data/cup_calendar.cpp \
    game/data/federation.cpp \
    game/data/fifa.cpp \
    game/data/game_data.cpp \
    game/data/league.cpp \
    game/data/league_calendar.cpp \
    game/data/match.cpp \
    game/data/match_lineup.cpp \
    game/data/player.cpp \
    game/data/player_position.cpp \
    game/data/player_search_filter.cpp \
    game/data/scheduled_match.cpp \
    game/data/stadium.cpp \
    game/data/table.cpp \
    game/data/team.cpp \
    game/data/team_in_game.cpp \
    game/events/event.cpp \
    game/events/event_array.cpp \
    game/events/event_birthday.cpp \
    game/events/event_handler.cpp \
    game/events/event_match.cpp \
    game/game.cpp \
    game/time/date.cpp \
    game/user/user.cpp \
    json/json_parser.cpp \
    json/json_parser_club.cpp \
    json/json_parser_player.cpp \
    json/json_parser_squad.cpp \
    main/data_collector.cpp \
    main/main.cpp \
    main/mainwindow.cpp \
    main/mainwindow_database.cpp \
    network/network_manager.cpp \
    network/request_buffer.cpp \
    ui/scenes/home_scene.cpp \
    ui/scenes/new_game_scene.cpp \
    ui/scenes/operational/scene_operational.cpp \
    ui/scenes/operational/scene_switch.cpp \
    ui/scenes/settings_scene.cpp \
    ui/scenes/squad_scene.cpp \
    ui/scenes/starting_scene.cpp \
    ui/scenes/transfers_scene.cpp \
    ui/widgets/layout_general.cpp \
    ui/widgets/widget_general.cpp \
    ui/widgets/widget_qss_image_resize.cpp

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
    files/tmp_files.h \
    game/data/calendar.h \
    game/data/coach.h \
    game/data/competition.h \
    game/data/confederation.h \
    game/data/country_map.h \
    game/data/cup.h \
    game/data/cup_calendar.h \
    game/data/data_defs.h \
    game/data/federation.h \
    game/data/fifa.h \
    game/data/game_data.h \
    game/data/league.h \
    game/data/league_calendar.h \
    game/data/match.h \
    game/data/match_lineup.h \
    game/data/player.h \
    game/data/player_position.h \
    game/data/player_search_filter.h \
    game/data/scheduled_match.h \
    game/data/stadium.h \
    game/data/table.h \
    game/data/team.h \
    game/data/team_in_game.h \
    game/events/event.h \
    game/events/event_array.h \
    game/events/event_birthday.h \
    game/events/event_handler.h \
    game/events/event_match.h \
    game/game.h \
    game/time/date.h \
    game/user/user.h \
    json/json_parser.h \
    json/json_parser_club.h \
    json/json_parser_player.h \
    json/json_parser_squad.h \
    main/mainwindow.h \
    network/network_manager.h \
    network/request_buffer.h \
    ui/scenes/operational/scene_switch.h \
    ui/scenes/operational/scenes_defs.h \
    ui/widgets/widget_qss_image_resize.h

FORMS += \
    ui/mainwindow.ui \

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ../../Resources/backgrounds.qrc \
    ../../Resources/flags.qrc \
    ../../Resources/icons.qrc \
    ../../Resources/logos.qrc
