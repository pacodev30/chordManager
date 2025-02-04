#include <GuitarChord.h>
#include <iostream>

GuitarChord::GuitarChord(ENote tonal, EChordType type, std::string tab)
    : Chord(tonal, type), _tab(tab)
{}

///
/// \brief GuitarChord::getTab
/// \return  string
///
std::string GuitarChord::getTab() const
{
    return _tab;
}

///
/// \brief GuitarChord::setTab
/// \param newTab
///
void GuitarChord::setTab(const std::string& newTab)
{
    _tab = newTab;
}

///
/// \brief GuitarChord::printChord
///
void GuitarChord::printChord() const
{
    Chord::printChord();
    std::cout << "Guitar tab :" << std::endl;
    std::cout << _tab << "\n---" << std::endl;
}

