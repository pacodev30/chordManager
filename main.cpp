#include <ChordManager.h>
#include <GuitarChord.h>

int main()
{
    ChordManager m;

    // CREATE CHORDS
    m.addChord(ENote::DO, EChordName::M7M);
    m.addChord(ENote::RE, EChordName::m7);
    m.addChord(ENote::MI, EChordName::m);
    m.addChord(ENote::FA, EChordName::M);
    m.addChord(ENote::SOL, EChordName::Dom7);
    m.addChord(ENote::LA, EChordName::m6);
    m.addChord(ENote::SI, EChordName::m7b5);

    // CREATE GUITARCHORD
    std::string c_tab = "|O|-|-|\n"
                        "|O|-|-|\n"
                        "|-|O|-|\n"
                        "|-|-|O|\n"
                        "|-|-|O|\n"
                        "|O|-|-|\n";
    m.addChord(ENote::MIb, EChordName::M, EChordType::GUITARCHORD, c_tab);

    // MANAGE CHORD
    m.addChord(ENote::LAb, EChordName::dim);
    m.addNoteToChord("Abdim", EInterval::QUINTE_aug);
    m.deleteNoteFromChord("Abdim", QUINTE_aug);
    m.deleteChord("Abdim");

    m.printChords();

    return 0;
}
