#include <ChordManager.h>
#include <iostream>

ChordManager::ChordManager()
{}
ChordManager::~ChordManager()
{
    for(Chord* chord : _chords)
    {
        // std::cout << chord->getName() << "* Deleted " << std::endl;
        delete chord;
        chord = nullptr;
    }
    _chords.clear();
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
std::vector<EInterval> ChordManager::getIntervals() const
{
    return _intervals;
}

///
/// \brief ChordManager::addChord
/// \param tonal
/// \param type
///
void ChordManager::addChord(const ENote tonal, const EChordType type)
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

    for(EInterval i : setIntervals(type))
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
void ChordManager::addNoteToChord(const std::string& chordName, const EInterval interval)
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
void ChordManager::deleteNoteFromChord(const std::string& chordName, const EInterval interval)
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
std::vector<EInterval> ChordManager::setIntervals(const EChordType type)
{
    switch(type)
    {
    case EChordType::M: return {EInterval::TONIQUE, EInterval::TIERCE, EInterval::QUINTE};
    case EChordType::M69: return {EInterval::SECONDE, EInterval::TIERCE, EInterval::QUINTE, EInterval::SIXTE};
    case EChordType::M7M: return {EInterval::TONIQUE, EInterval::TIERCE, EInterval::QUINTE, EInterval::SEPTIEME};
    case EChordType::m: return {EInterval::TONIQUE, EInterval::TIERCE_min, EInterval::QUINTE};
    case EChordType::m6: return {EInterval::TONIQUE, EInterval::TIERCE_min, EInterval::QUINTE, EInterval::SIXTE};
    case EChordType::m7: return {EInterval::TONIQUE, EInterval::TIERCE_min, EInterval::QUINTE, EInterval::SEPTIEME_min};
    case EChordType::Dom7: return {EInterval::TONIQUE, EInterval::TIERCE, EInterval::QUINTE, EInterval::SEPTIEME_min};
    case EChordType::Dom79b: return {EInterval::SECONDE_min, EInterval::TIERCE, EInterval::QUINTE, EInterval::SEPTIEME_min};
    case EChordType::dim: return {EInterval::TONIQUE, EInterval::TIERCE, EInterval::QUINTE_dim};
    case EChordType::m7b5: return {EInterval::TONIQUE, EInterval::TIERCE_min, EInterval::QUINTE_dim};
    }
}
