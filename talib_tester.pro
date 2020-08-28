TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main_talib_tester.cpp
HEADERS += \
    talib/include/ta_func.h \
    talib/include/ta_libc.h
unix:!macx: LIBS += -L$$PWD/talib/libs/linux64/ -lta_lib

INCLUDEPATH += $$PWD/talib/libs/linux64
DEPENDPATH += $$PWD/talib/libs/linux64

win32: LIBS += -L$$PWD/talib/libs/win64/ -lta_libc_cmr

INCLUDEPATH += $$PWD/talib/libs/win64
DEPENDPATH += $$PWD/talib/libs/win64
