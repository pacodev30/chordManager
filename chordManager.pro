TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        Chord.cpp \
        ChordManager.cpp \
        GuitarChord.cpp \
        PianoChord.cpp \
        main.cpp

HEADERS += \
    Chord.h \
    ChordManager.h \
    Data.h \
    GuitarChord.h \
    PianoChord.h
