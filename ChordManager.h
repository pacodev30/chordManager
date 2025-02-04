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
    std::vector<EInterval> getIntervals() const;

    /**
     * @brief addChord
     * @param tonal
     * @param type
     */
    void addChord(const ENote tonal, const EChordType type);

    ///
    /// \brief addGuitarChord
    /// \param guitarChord
    ///
    void addGuitarChord(Chord* guitarChord);

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

    ///
    /// \brief setIntervals
    /// \param type
    /// \return
    ///
    std::vector<EInterval> setIntervals(const EChordType type);

private:
    std::vector<EInterval> _intervals;
    std::vector<Chord*> _chords;
};
