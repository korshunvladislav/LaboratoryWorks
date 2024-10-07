#ifndef AMINOACIDTRANSLATOR_H
#define AMINOACIDTRANSLATOR_H

#include <map>
#include <string>

using namespace std;

class AminoAcidTranslator {
public:
    AminoAcidTranslator();

    char translate(const string& codon); // Метод перевода кодона в аминокислоту

private:
    map<string, char> codonTable; // Таблица кодонов
};

#endif
