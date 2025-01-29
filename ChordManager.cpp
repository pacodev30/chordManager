#include <ChordManager.h>
#include <iostream>

ChordManager::ChordManager()
{}
ChordManager::~ChordManager()
{
    for(Chord* chord : _chords)
    {
        std::cout << chord->getName() << "* Deleted " << std::endl;
        delete chord;
        chord = nullptr;
    }
}

///
/// \brief ChordManager::printChords
///
void ChordManager::printChords() const
{
    if(_chords.empty())
    {
        std::cout << "No chord added" << std::endl;
        return;
    }

    for(Chord* c : _chords)
    {
        c->printChord();
    }
}

///
/// \brief ChordManager::getIntervals
/// \return vector<Interval>
///
std::vector<INTERVAL> ChordManager::getIntervals() const
{
    return _intervals;
}

///
/// \brief ChordManager::addChord
/// \param tonal
/// \param type
///
void ChordManager::addChord(const NOTE tonal, const CHORDTYPE type)
{
    std::string name = Data::tonalToString(tonal) + Data::typeToString(type);

    for(Chord* c : _chords)
    {
        if(c->getName() == name)
        {
            std::cout << name << " already exist" << std::endl;
            return;
        }
    }

    _chords.emplace_back(new Chord(tonal, type));

    for(INTERVAL i : setIntervals(type))
    {
        addNoteToChord(name, i);
    }
}

void ChordManager::addGuitarChord(Chord* guitarChord)
{
    _chords.emplace_back(guitarChord);
}

///
/// \brief ChordManager::deleteChord
/// \param chordName
///
void ChordManager::deleteChord(const std::string& chordName)
{
    for(size_t i = 0; i < _chords.size(); i++)
    {
        if(_chords.at(i)->getName() == chordName)
        {
            delete _chords.at(i);
            _chords.at(i) = nullptr;
            _chords.erase(_chords.begin() + i);
            std::cout << chordName << " is deleted succesfully" << std::endl;
        }
        else {
            std::cout << chordName << " is not found" << std::endl;
        }
    }
}

///
/// \brief ChordManager::addNoteToChord
/// \param chordName
/// \param interval
///
void ChordManager::addNoteToChord(const std::string& chordName, const INTERVAL interval)
{
    for(Chord* c : _chords)
    {
        if(c->getName() == chordName)
        {
            c->addToArpeggio(interval);
        }
    }
}

///
/// \brief ChordManager::deleteNoteFromChord
/// \param chordName
/// \param interval
///
void ChordManager::deleteNoteFromChord(const std::string& chordName, const INTERVAL interval)
{
    for(Chord* c : _chords)
    {
        if(c->getName() == chordName)
        {
            c->DeleteFromArpeggio(interval);
            std::cout << "Interval "
                      << Data::intervalToString(interval)
                      << " is deleted succesfully from "
                      << c->getName() << "\n"
                      << std::endl;
        }
    }
}

///
/// \brief ChordManager::setIntervals
/// \param type
/// \return  vector<Interval>
///
std::vector<INTERVAL> ChordManager::setIntervals(const CHORDTYPE type)
{
    switch(type)
    {
    case CHORDTYPE::M: return {INTERVAL::TONIQUE, INTERVAL::TIERCE, INTERVAL::QUINTE};
    case CHORDTYPE::M69: return {INTERVAL::SECONDE, INTERVAL::TIERCE, INTERVAL::QUINTE, INTERVAL::SIXTE};
    case CHORDTYPE::M7M: return {INTERVAL::TONIQUE, INTERVAL::TIERCE, INTERVAL::QUINTE, INTERVAL::SEPTIEME};
    case CHORDTYPE::m: return {INTERVAL::TONIQUE, INTERVAL::TIERCE_min, INTERVAL::QUINTE};
    case CHORDTYPE::m6: return {INTERVAL::TONIQUE, INTERVAL::TIERCE_min, INTERVAL::QUINTE, INTERVAL::SIXTE};
    case CHORDTYPE::m7: return {INTERVAL::TONIQUE, INTERVAL::TIERCE_min, INTERVAL::QUINTE, INTERVAL::SEPTIEME_min};
    case CHORDTYPE::Dom7: return {INTERVAL::TONIQUE, INTERVAL::TIERCE, INTERVAL::QUINTE, INTERVAL::SEPTIEME_min};
    case CHORDTYPE::Dom79b: return {INTERVAL::SECONDE_min, INTERVAL::TIERCE, INTERVAL::QUINTE, INTERVAL::SEPTIEME_min};
    case CHORDTYPE::dim: return {INTERVAL::TONIQUE, INTERVAL::TIERCE, INTERVAL::QUINTE_dim};
    case CHORDTYPE::m7b5: return {INTERVAL::TONIQUE, INTERVAL::TIERCE_min, INTERVAL::QUINTE_dim};
    }
}
