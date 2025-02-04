#pragma once
#include <Data.h>
#include <Map>
#include <string>

class Chord
{
public:
    Chord(ENote tonal, EChordType type);
    virtual ~Chord();

    ///
    /// \brief getName
    /// \return
    ///
    std::string getName() const;

    ///
    /// \brief setName
    ///
    void setName();

    ///
    /// \brief printChord
    ///
    virtual void printChord() const;

    ///
    /// \brief intervalToNote
    /// \param interval
    /// \return
    ///
    ENote intervalToNote(const EInterval interval) const;

    ///
    /// \brief addToArpeggio
    /// \param interval
    ///
    void addToArpeggio(const EInterval interval);

    ///
    /// \brief DeleteFromArpeggio
    /// \param interval
    ///
    void DeleteFromArpeggio(const EInterval interval);

protected:
    ENote _tonal;
    EChordType _type;
    std::string _name;

    std::map<EInterval, ENote> _arpeggio;
};
