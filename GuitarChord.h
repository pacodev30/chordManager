#pragma once

#include <Data.h>
#include <Chord.h>

class GuitarChord : public Chord
{
public:
    GuitarChord(ENote tonal, EChordType type, std::string tab);

    ///
    /// \brief getTab
    /// \return
    ///
    std::string getTab() const;

    ///
    /// \brief setTab
    /// \param newTab
    ///
    void setTab(const std::string& newTab);

    ///
    /// \brief printChord
    ///
    void printChord() const override;

private:
    std::string _tab;
};
