#ifndef PROTEINSEQUENCE_H
#define PROTEINSEQUENCE_H

#include <vector>
#include <string>
#include "AminoAcidTranslator.h"
#include "AminoAcid.h"

using namespace std;

class ProteinSequence {
public:
    ProteinSequence(); // Конструктор по умолчанию
    ProteinSequence(const vector<AminoAcid>& aminoAcids); // Конструктор инициализации
    ProteinSequence(const ProteinSequence& other); // Конструктор копирования
    ProteinSequence& operator=(const ProteinSequence& other); // Оператор присваивания

    void addCodon(const string& codon);
    string getSequence() const; // Возвращаем последовательность аминокислот

    // Объединяем две последовательности по совпадающему фрагменту
    static ProteinSequence merge(const ProteinSequence& seq1, const ProteinSequence& seq2);

private:
    vector<char> aminoAcids;
    AminoAcidTranslator translator; // Объект для перевода кодонов
};

#endif
