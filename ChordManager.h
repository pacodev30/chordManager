#pragma once
#include <Chord.h>
#include <Data.h>
#include <vector>

class ChordManager
{
public:
    ChordManager();
    ~ChordManager();

    void createChord(NOTE tonal, CHORDTYPE type);
    void readChord();
    void UpdateChord();
    void deleteChord();

    void printChords() const;
    std::vector<INTERVAL> getIntervals() const;

    void addChord(const NOTE tonal, const CHORDTYPE type);
    void addGuitarChord(Chord* guitarChord);
    void deleteChord(const std::string& chordName);


    void addNoteToChord(const std::string& chordName, const INTERVAL interval);
    void deleteNoteFromChord(const std::string& chordName, const INTERVAL interval);

    std::vector<INTERVAL> setIntervals(const CHORDTYPE type);

private:
    std::vector<INTERVAL> _intervals;
    std::vector<Chord*> _chords;
};
