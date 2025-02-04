#pragma once

#include <Data.h>
#include <Chord.h>

class GuitarChord : public Chord
{
public:
    GuitarChord(ENote tonal, EChordType chordType, std::string tab);

    ///
    /// \brief printChord
    ///
    void printChord() const override;

private:
    std::string _tab;
};
