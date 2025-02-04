#include <ChordManager.h>
#include <PianoChord.h>
#include <GuitarChord.h>
#include <iostream>

ChordManager::ChordManager()
{}
ChordManager::~ChordManager()
{
    for(Chord* chord : _chords)
    {
        delete chord;
        chord = nullptr;
    }
    _chords.clear();
}

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

void ChordManager::addChord(const ENote tonal, const EChordName chordName,EChordType type, std::string tab)
{
    std::string name = Data::tonalToString(tonal) + Data::chordNameToString(chordName);

    for(Chord* c : _chords)
    {
        if(c->getName() == name)
        {
            std::cout << name << " already exist" << std::endl;
            return;
        }
    }

    if(type == EChordType::PIANOCHORD)
        _chords.emplace_back(new PianoChord(tonal, chordName));

    else if(type == EChordType::GUITARCHORD)
        _chords.emplace_back(new GuitarChord(tonal, chordName, tab));

    for(EInterval i : Data::chordNameToIntervals(chordName))
    {
        addNoteToChord(name, i);
    }
}

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
            return;
        }
    }
    std::cout << chordName << " is not found to delete" << std::endl;
}

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
