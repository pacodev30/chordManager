#pragma once
#include <Chord.h>
#include <Data.h>
#include <vector>

class ChordManager
{
public:
    ChordManager();
    ~ChordManager();

    void printChords() const;

    /**
     * @brief addChord
     * @param tonal
     * @param type
     */
    void addChord(const ENote tonal, const EChordName chordName, EChordType type = EChordType::PIANOCHORD, std::string tab = "");

    /**
     * @brief deleteChord
     * @param chordName
     */
    void deleteChord(const std::string& chordName);

    ///
    /// \brief addNoteToChord
    /// \param chordName
    /// \param interval
    ///
    void addNoteToChord(const std::string& chordName, const EInterval interval);

    ///
    /// \brief deleteNoteFromChord
    /// \param chordName
    /// \param interval
    ///
    void deleteNoteFromChord(const std::string& chordName, const EInterval interval);

private:
    std::vector<Chord*> _chords;
};
