#pragma once

#include <Chord.h>

class PianoChord : public Chord
{
public:
    PianoChord(ENote note, EChordType chordType);

    /**
     * @brief printChord
     */
    void printChord() const override;
};
