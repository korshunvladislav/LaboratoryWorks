#ifndef EXTENDEDPROTEINSEQUENCE_H
#define EXTENDEDPROTEINSEQUENCE_H

#include <vector>
#include "AminoAcidTranslator.h"
#include "AminoAcid.h"
#include "ProteinSequence.h"

using namespace std;

class ExtendedProteinSequence : public ProteinSequence {
public:
    ExtendedProteinSequence(); // Конструктор по умолчанию
    ExtendedProteinSequence(const vector<char>& aminoAcids); // Конструктор инициализации
    ExtendedProteinSequence(const ExtendedProteinSequence& other);

    string identify() const override {
        return "Класс наследуемый от Protein Sequence";
    }

    void synthesizeFromNucleotides(const string& nucleotideSequence); // Синтез из нуклеотидов

    virtual ~ExtendedProteinSequence() {}
};

#endif