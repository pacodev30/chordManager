#pragma once

#include <Chord.h>

class PianoChord : public Chord
{
public:
    PianoChord(ENote note, EChordName chordname);

    void printChord() const override;
};
