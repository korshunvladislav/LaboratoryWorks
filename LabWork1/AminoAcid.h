#ifndef AMINOACID_H
#define AMINOACID_H

#include <string>

class AminoAcid {
public:
    AminoAcid(); // Конструктор по умолчанию
    AminoAcid(char code); // Конструктор инициализации
    AminoAcid(const AminoAcid& other); // Конструктор копирования
    AminoAcid& operator=(const AminoAcid& other); // Оператор присваивания

    char getCode() const; // Метод для получения кода аминокислоты

private:
    char code; // Код аминокислоты (одна буква)
};

#endif
