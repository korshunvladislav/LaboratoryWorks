#include "Protein.h"

using namespace std;

// Конструктор из строки
Protein::Protein(const string& seq) {
    sequence.assign(seq.begin(), seq.end());
}

string Protein::getSequence() const {
    return string(sequence.begin(), sequence.end());
}

Protein Protein::operator+(const Protein &other) const {
    // Ищем максимальное пересечение
    size_t overlap = 0;
    for (size_t i = 0; i < sequence.size(); ++i) {
        if (equal(sequence.begin() + i, sequence.end(), other.sequence.begin())) {
            overlap = sequence.size() - i;
            break;
        }
    }

    vector<char> result(sequence.begin(), sequence.end());
    result.insert(result.end(), other.sequence.begin() + overlap, other.sequence.end());

    return Protein(string(result.begin(), result.end()));
}

ostream& operator<<(ostream& os, const Protein& protein) {
    os << protein.getSequence();
    return os;
}