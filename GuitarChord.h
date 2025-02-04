#pragma once

#include <Data.h>
#include <Chord.h>

class GuitarChord : public Chord
{
public:
    GuitarChord(ENote tonal, EChordName chordName, std::string tab);

    ///
    /// \brief printChord
    ///
    void printChord() const override;

private:
    std::string _tab;
};
