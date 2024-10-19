#include "ExtendedProteinSequence.h"

using namespace std;

// Конструктор по умолчанию
ExtendedProteinSequence::ExtendedProteinSequence() : ProteinSequence() {}

// Конструктор инициализации
ExtendedProteinSequence::ExtendedProteinSequence(const vector<char>& aminoAcids)
        : ProteinSequence(aminoAcids) {}

// Конструктор копирования
ExtendedProteinSequence::ExtendedProteinSequence(const ExtendedProteinSequence& other)
        : ProteinSequence(other) {}

// Синтез из нуклеотидов
void ExtendedProteinSequence::synthesizeFromNucleotides(const string& nucleotideSequence) {
    for (size_t i = 0; i + 2 < nucleotideSequence.length(); i += 3) {
        string codon = nucleotideSequence.substr(i, 3);
        addCodon(codon);
    }
}
