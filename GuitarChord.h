#pragma once

#include <Data.h>
#include <Chord.h>

class GuitarChord : public Chord
{
public:
    GuitarChord(NOTE tonal, CHORDTYPE type, std::string tab);

    std::string getTab() const;
    void setTab(const std::string& newTab);

    void printChord() const override;

private:
    std::string _tab;
};
