#include "AminoAcidTranslator.h"

using namespace std;

AminoAcidTranslator::AminoAcidTranslator() {
    codonTable["UUU"] = 'F'; // Фенилаланин
    codonTable["UUC"] = 'F';
    codonTable["UUA"] = 'L'; // Лейцин
    codonTable["UUG"] = 'L';
    codonTable["CUU"] = 'L';
    codonTable["CUC"] = 'L';
    codonTable["CUA"] = 'L';
    codonTable["CUG"] = 'L';
    codonTable["AUU"] = 'I'; // Изолейцин
    codonTable["AUC"] = 'I';
    codonTable["AUA"] = 'I';
    codonTable["AUG"] = 'M'; // Метионин
    codonTable["GUU"] = 'V'; // Валин
    codonTable["GUC"] = 'V';
    codonTable["GUA"] = 'V';
    codonTable["GUG"] = 'V';
    codonTable["UCU"] = 'S'; // Серин
    codonTable["UCC"] = 'S';
    codonTable["UCA"] = 'S';
    codonTable["UCG"] = 'S';
    codonTable["CCU"] = 'P'; // Пролин
    codonTable["CCC"] = 'P';
    codonTable["CCA"] = 'P';
    codonTable["CCG"] = 'P';
    codonTable["ACU"] = 'T'; // Треонин
    codonTable["ACC"] = 'T';
    codonTable["ACA"] = 'T';
    codonTable["ACG"] = 'T';
    codonTable["GCU"] = 'A'; // Аланин
    codonTable["GCC"] = 'A';
    codonTable["GCA"] = 'A';
    codonTable["GCG"] = 'A';
    codonTable["UAU"] = 'Y'; // Тирозин
    codonTable["UAC"] = 'Y';
    codonTable["UAA"] = '*'; // Стоп-кодоны
    codonTable["UAG"] = '*';
    codonTable["CAU"] = 'H'; // Гистидин
    codonTable["CAC"] = 'H';
    codonTable["CAA"] = 'Q'; // Глутамин
    codonTable["CAG"] = 'Q';
    codonTable["AAU"] = 'N'; // Аспарагин
    codonTable["AAC"] = 'N';
    codonTable["AAA"] = 'K'; // Лизин
    codonTable["AAG"] = 'K';
    codonTable["GAU"] = 'D'; // Аспарагиновая кислота
    codonTable["GAC"] = 'D';
    codonTable["GAA"] = 'E'; // Глутаминовая кислота
    codonTable["GAG"] = 'E';
    codonTable["UGU"] = 'C'; // Цистеин
    codonTable["UGC"] = 'C';
    codonTable["UGA"] = '*'; // Стоп-кодон
    codonTable["GGU"] = 'G'; // Глицин
    codonTable["GGC"] = 'G';
    codonTable["GGA"] = 'G';
    codonTable["GGG"] = 'G';
}

char AminoAcidTranslator::translate(const string& codon) {
    auto it = codonTable.find(codon);
    if (it != codonTable.end()) {
        return it->second; // Возврат соответствующей аминокислоты
    }
    throw invalid_argument("Неверный кодон"); // Ошибка, если кодон не найден
}
