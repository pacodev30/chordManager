#include <PianoChord.h>
#include <iostream>

PianoChord::PianoChord(ENote note, EChordName chordname)
    : Chord(note, chordname)
{}

void PianoChord::printChord() const
{
    std::cout << "---" << std::endl;
    std::cout << getName() << std::endl;
    for(auto arp : _arpeggio)
    {
        std::cout   << Data::intervalToString(arp.first)
        << " -> "
        << Data::noteToString(intervalToNote(arp.first)) << std::endl;
    }
}
