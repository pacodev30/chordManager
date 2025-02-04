#pragma once
#include <string>
#include <vector>

enum EChordFamily
{
    PIANOCHORD,
    GUITARCHORD
};

enum EChordType
{
    M,
    M69,
    M7M,
    m,
    m6,
    m7,
    Dom7,
    Dom79b,
    dim,
    m7b5
};

enum EInterval
{
    TONIQUE,
    SECONDE_min,
    SECONDE,
    TIERCE_min,
    TIERCE,
    QUARTE,
    QUINTE_dim,
    QUINTE,
    QUINTE_aug,
    SIXTE,
    SEPTIEME_min,
    SEPTIEME,
};

enum ENote
{
    DO,
    REb,
    RE,
    MIb,
    MI,
    FA,
    SOLb,
    SOL,
    LAb,
    LA,
    SIb,
    SI
};

class Data
{
public:

    /**
     * @brief chordNameToString
     * @param chordType
     * @return
     */
    static std::string chordNameToString(EChordType chordType)
    {
        switch (chordType)
        {
        case M: return "";
        case M69: return "6add9";
        case M7M: return "7M";
        case m: return "m";
        case m6:return "m6";
        case m7: return "m7";
        case Dom7: return "7";
        case Dom79b: return "79b";
        case dim: return "dim";
        case m7b5: return "m7b5";
        }
    }

    /**
     * @brief intervalToString
     * @param interval
     * @return
     */
    static std::string intervalToString(EInterval interval)
    {
        switch (interval)
        {
        case TONIQUE: return "T";
        case SECONDE_min: return "2m";
        case SECONDE: return "2";
        case TIERCE_min: return "3m";
        case TIERCE: return "3";
        case QUARTE: return "4";
        case QUINTE: return "5";
        case QUINTE_aug: return "5aug";
        case QUINTE_dim: return "5dim";
        case SIXTE: return "6";
        case SEPTIEME_min: return "7m";
        case SEPTIEME: return "7M";
        }
    }

    /**
     * @brief noteToString
     * @param note
     * @return
     */
    static std::string noteToString(ENote note)
    {
        switch (note)
        {
        case DO: return "Do";
        case REb: return "Reb";
        case RE: return "Re";
        case MIb: return "Mib";
        case MI: return "Mi";
        case FA: return "Fa";
        case SOLb: return "Solb";
        case SOL: return "Sol";
        case LAb: return "Lab";
        case LA: return "La";
        case SIb: return "Sib";
        case SI: return "Si";
        }
    }

    /**
     * @brief tonalToString
     * @param note
     * @return
     */
    static std::string tonalToString(ENote note)
    {
        switch (note)
        {
        case DO: return "C";
        case REb: return "Db";
        case RE: return "D";
        case MIb: return "Eb";
        case MI: return "E";
        case FA: return "F";
        case SOLb: return "Gb";
        case SOL: return "G";
        case LAb: return "Ab";
        case LA: return "A";
        case SIb: return "Bb";
        case SI: return "B";
        }
    }

    /**
     * @brief chordNameToIntervals
     * @param chordType
     * @return
     */
    static std::vector<EInterval> chordNameToIntervals(const EChordType chordType)
    {
        switch(chordType)
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
};
