#include <Chord.h>
#include <iostream>

Chord::Chord(ENote tonal, EChordName chordName)
    : _tonal(tonal), _type(chordName)
{
    setName();
}

Chord::~Chord()
{ }

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
    _name = Data::tonalToString(_tonal) + Data::chordNameToString(_type);
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
ENote Chord::intervalToNote(const EInterval interval) const
{
    int indexNote = interval + _tonal;
    if(indexNote > ENote::SI)
    {
        indexNote -= ENote::SI + 1;
    }
    return static_cast<ENote>(indexNote);
}

///
/// \brief Chord::addToArpeggio
/// \param interval
///
void Chord::addToArpeggio(const EInterval interval)
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
void Chord::DeleteFromArpeggio(const EInterval interval)
{
    auto it = _arpeggio.find(interval);
    _arpeggio.erase(it);
}




