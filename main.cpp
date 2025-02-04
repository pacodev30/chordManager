#include <ChordManager.h>
#include <GuitarChord.h>

int main()
{
    ChordManager m;

    // CREATE CHORDS
    m.addChord(ENote::DO, EChordType::M7M);
    m.addChord(ENote::RE, EChordType::m7);
    m.addChord(ENote::MI, EChordType::m);
    m.addChord(ENote::FA, EChordType::M);
    m.addChord(ENote::SOL, EChordType::Dom7);
    m.addChord(ENote::LA, EChordType::m6);
    m.addChord(ENote::SI, EChordType::m7b5);


    m.addChord(ENote::LAb, EChordType::dim);
    m.addNoteToChord("Abdim", EInterval::QUINTE_aug);
    m.deleteNoteFromChord("Abdim", QUINTE_aug);

    // CREATE GUITARCHORD
    std::string c_tab = "|O|x|x|\n"
                        "|O|x|x|\n"
                        "|x|O|x|\n"
                        "|x|x|O|\n"
                        "|x|x|O|\n"
                        "|O|x|x|\n";

    GuitarChord* c_guit = new GuitarChord(ENote::REb, EChordType::M, c_tab);
    c_guit->addToArpeggio(EInterval::TONIQUE);
    c_guit->addToArpeggio(EInterval::TIERCE);
    c_guit->addToArpeggio(EInterval::QUINTE);

    // MANAGE CHORDS
    m.addGuitarChord(c_guit);
    m.printChords();

    return 0;
}
