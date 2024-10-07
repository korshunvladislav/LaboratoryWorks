#include "ProteinSequence.h"

using namespace std;

// Конструктор по умолчанию
ProteinSequence::ProteinSequence() : aminoAcids(), translator() {}

// Конструктор инициализации
ProteinSequence::ProteinSequence(const vector<char>& aminoAcids)
    : aminoAcids(aminoAcids), translator() {
}

// Конструктор копирования
ProteinSequence::ProteinSequence(const ProteinSequence& other)
    : aminoAcids(other.aminoAcids), translator(other.translator) {
}

// Оператор присваивания
ProteinSequence& ProteinSequence::operator=(const ProteinSequence& other) {
    if (this != &other) {
        aminoAcids = other.aminoAcids; // Копируем вектор аминокислот
        translator = other.translator;
    }
    return *this;
}

void ProteinSequence::addCodon(const string& codon) {
    char aminoAcid = translator.translate(codon);
    aminoAcids.push_back(aminoAcid); // Добавляем аминокислоту
}

string ProteinSequence::getSequence() const {
    return string(aminoAcids.begin(), aminoAcids.end()); // Преобразуем в строку
}

ProteinSequence ProteinSequence::merge(const ProteinSequence& seq1, const ProteinSequence& seq2) {
    ProteinSequence result = seq1;

    // Ищем, где заканчиваются совпадающие фрагменты
    string seq1_str = seq1.getSequence();
    string seq2_str = seq2.getSequence();
    size_t overlap = seq1_str.size();

    while (overlap > 0) {
        if (seq1_str.substr(seq1_str.size() - overlap) == seq2_str.substr(0, overlap)) {
            break;
        }
        overlap--;
    }

    // Добавляем оставшуюся часть второй последовательности
    for (size_t i = overlap; i < seq2.aminoAcids.size(); ++i) {
        result.aminoAcids.push_back(seq2.aminoAcids[i]);
    }

    return result;
}
