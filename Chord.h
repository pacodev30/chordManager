#pragma once
#include <Data.h>
#include <map>
#include <string>

class Chord
{
public:
    Chord(NOTE tonal, CHORDTYPE type);
    virtual ~Chord();

    std::string getName() const;
    void setName();

    virtual void printChord() const;

    NOTE intervalToNote(INTERVAL interval) const;
    void addToArpeggio(INTERVAL interval);
    void DeleteFromArpeggio(const INTERVAL interval);

protected:
    NOTE _tonal;
    CHORDTYPE _type;
    std::string _name;

    std::map<INTERVAL, NOTE> _arpeggio;
};
