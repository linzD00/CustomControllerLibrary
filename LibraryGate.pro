QT += widgets

HEADERS += \
    Gatewin.h \
    notelabelSlider.h \
    slideredit.h

SOURCES += \
        Gatewin.cpp \
        main.cpp \
        notelabelSlider.cpp \
        slideredit.cpp

TRANSLATIONS += \
    LibraryGate_zh_CN.ts

target.path = /tmp/$${TARGET}/bin
INSTALLS += target



