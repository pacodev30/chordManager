#include <ChordManager.h>
#include <GuitarChord.h>

int main()
{
    ChordManager m;

    // CREATE CHORDS
    m.addChord(ENote::DO,  EChordType::M7M);
    m.addChord(ENote::RE,  EChordType::m7);
    m.addChord(ENote::MI,  EChordType::m);
    m.addChord(ENote::FA,  EChordType::M);
    m.addChord(ENote::SOL, EChordType::Dom7);
    m.addChord(ENote::LA,  EChordType::m6);
    m.addChord(ENote::SI,  EChordType::m7b5);

    // CREATE GUITARCHORD
    std::string c_tab = "|O|-|-|\n"
                        "|O|-|-|\n"
                        "|-|O|-|\n"
                        "|-|-|O|\n"
                        "|-|-|O|\n"
                        "|O|-|-|\n";
    m.addChord(ENote::MIb, EChordType::M, EChordFamily::GUITARCHORD, c_tab);

    // MANAGE CHORD
    m.addChord(ENote::LAb, EChordType::dim);
    m.addNoteToChord("Abdim", EInterval::QUINTE_aug);
    m.deleteNoteFromChord("Abdim", QUINTE_aug);
    m.deleteChord("Abdim");

    m.printChords();

    return 0;
}
