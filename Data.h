#pragma once
#include <string>

enum CHORDTYPE
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

enum INTERVAL
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

enum NOTE
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

    static std::string typeToString(CHORDTYPE type)
    {
        switch (type)
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

    static std::string intervalToString(INTERVAL interval)
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

    static std::string noteToString(NOTE note)
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

    static std::string tonalToString(NOTE note)
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
};
