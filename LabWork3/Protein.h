#ifndef PROTEIN_H
#define PROTEIN_H

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

class Protein {
private:
    vector<char> sequence;

public:
    Protein() = default; // Конструктор по умолчанию
    Protein(const string& seq); // Конструктор из строки

    Protein operator+(const Protein& other) const; // Перегрузка оператора сложения

    string getSequence() const; // Получение последовательности как строки

    friend ostream& operator<<(ostream& os, const Protein& protein); // Вывод белка
};

#endif
