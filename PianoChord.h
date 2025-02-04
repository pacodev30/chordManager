#pragma once

#include <Chord.h>

class PianoChord : public Chord
{
public:
    PianoChord(ENote note, EChordType chordType);

    void printChord() const override;
};
