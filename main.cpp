#include <ChordManager.h>
#include <GuitarChord.h>
#include "Data.h"
int main()
{
    ChordManager m;

    // CREATE CHORDS
    m.addChord(NOTE::DO, CHORDTYPE::M7M);
    m.addChord(NOTE::RE, CHORDTYPE::m7);
    m.addChord(NOTE::MI, CHORDTYPE::m);
    m.addChord(NOTE::FA, CHORDTYPE::M);
    m.addChord(NOTE::SOL, CHORDTYPE::Dom7);
    m.addChord(NOTE::LA, CHORDTYPE::m6);
    m.addChord(NOTE::SI, CHORDTYPE::m7b5);

    // MANAGE CHORDS
    m.addChord(NOTE::LAb, CHORDTYPE::dim);
    m.addNoteToChord("Abdim", INTERVAL::QUINTE_aug);
    m.deleteNoteFromChord("Abdim", QUINTE_aug);

    // CREATE GUITARCHORD
    std::string c_tab = "|O|x|x|\n"
                        "|O|x|x|\n"
                        "|x|O|x|\n"
                        "|x|x|O|\n"
                        "|x|x|O|\n"
                        "|O|x|x|\n";

    GuitarChord* c_guit = new GuitarChord(NOTE::REb, CHORDTYPE::M, c_tab);
    c_guit->addToArpeggio(INTERVAL::TONIQUE);
    c_guit->addToArpeggio(INTERVAL::TIERCE);
    c_guit->addToArpeggio(INTERVAL::QUINTE);

    m.addGuitarChord(c_guit);

    m.printChords();

    return 0;
}
