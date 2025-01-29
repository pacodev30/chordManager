#include <Chord.h>
#include <iostream>

Chord::Chord(NOTE tonal, CHORDTYPE type)
    : _tonal(tonal), _type(type)
{
    setName();
}

Chord::~Chord()
{  }

///
/// \brief Chord::getName
/// \return string
///
std::string Chord::getName() const
{
    return _name;
}

///
/// \brief Chord::setName
///
void Chord::setName()
{
    _name = Data::tonalToString(_tonal) + Data::typeToString(_type);
}

///
/// \brief Chord::printChord
///
void Chord::printChord() const
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

///
/// \brief Chord::intervalToNote
/// \param interval
/// \return Chord
///
NOTE Chord::intervalToNote(INTERVAL interval) const
{
    int indexNote = interval + _tonal;
    if(indexNote > NOTE::SI)
    {
        indexNote -= NOTE::SI + 1;
    }
    return (NOTE)indexNote;
}

///
/// \brief Chord::addToArpeggio
/// \param interval
///
void Chord::addToArpeggio(const INTERVAL interval)
{
    for(auto arp : _arpeggio)
    {
        if(arp.first == interval)
        {
            std::cout << "Interval '" << Data::intervalToString(interval) << "' already exist" << std::endl;
            return;
        }
    }
    _arpeggio.insert({interval, intervalToNote(interval)});
}

///
/// \brief Chord::DeleteFromArpeggio
/// \param interval
///
void Chord::DeleteFromArpeggio(const INTERVAL interval)
{
    auto it = _arpeggio.find(interval);
    _arpeggio.erase(it);
}




