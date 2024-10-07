#include "AminoAcid.h"

// Конструктор по умолчанию
AminoAcid::AminoAcid() : code(' ') {}

// Конструктор инициализации
AminoAcid::AminoAcid(char code) : code(code) {}

// Конструктор копирования
AminoAcid::AminoAcid(const AminoAcid& other) : code(other.code) {}

// Оператор присваивания
AminoAcid& AminoAcid::operator=(const AminoAcid& other) {
    if (this != &other) {
        code = other.code;
    }
    return *this;
}

char AminoAcid::getCode() const {
    return code;
}
