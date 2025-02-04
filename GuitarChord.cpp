#include <GuitarChord.h>
#include <iostream>

GuitarChord::GuitarChord(ENote tonal, EChordName chordName, std::string tab)
    : Chord(tonal, chordName), _tab(tab)
{}

///
/// \brief GuitarChord::printChord
///
void GuitarChord::printChord() const
{
    std::cout << "---" << std::endl;
    std::cout << "Guitar chord : " + getName()<< std::endl;
    for(auto arp : _arpeggio)
    {
        std::cout   << Data::intervalToString(arp.first)
        << " -> "
        << Data::noteToString(intervalToNote(arp.first)) << std::endl;
    }
    std::cout << _tab << "\n---" << std::endl;
}

