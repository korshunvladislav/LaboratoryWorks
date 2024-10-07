#ifndef AMINOACIDTRANSLATOR_H
#define AMINOACIDTRANSLATOR_H

#include <map>
#include <string>

using namespace std;

class AminoAcidTranslator {
public:
    AminoAcidTranslator(); // Конструктор по умолчанию
    AminoAcidTranslator(const map<string, char>& customCodonTable); // Конструктор инициализации
    AminoAcidTranslator(const AminoAcidTranslator& other); // Конструктор копирования
    AminoAcidTranslator& operator=(const AminoAcidTranslator& other); // Оператор присваивания

    char translate(const string& codon); // Метод перевода кодона в аминокислоту

private:
    map<string, char> codonTable; // Таблица кодонов
};

#endif
