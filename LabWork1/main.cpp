#include <iostream>
#include <vector>
#include <cassert>
#include "AminoAcid.h"
#include "ProteinSequence.h"
#include "../LabWork2/ExtendedProteinSequence.h"

using namespace std;

int main() {
    ProteinSequence seq1;
    seq1.addCodon("AUG"); // M (метионин)
    seq1.addCodon("UUU"); // F (фенилаланин)
    seq1.addCodon("CUU"); // L (лейцин)

    assert(seq1.getSequence() == "MFL");

    // Тестирование конструктора по умолчанию
    ProteinSequence ps_default;
    assert(ps_default.getSequence().empty()); // Пустая последовательность

    // Тестирование конструктора инициализации
    vector<char> aminoAcids = {'A', 'C', 'D'};
    ProteinSequence ps_initial(aminoAcids);
    assert(ps_initial.getSequence() == "ACD"); // Проверяем, что последовательность правильная

    // Тестирование конструктора копирования
    ProteinSequence ps_copy(ps_initial);
    assert(ps_copy.getSequence() == "ACD"); // Проверяем, что скопированная последовательность правильная

    // Тестирование метода доступа к полю
    assert(ps_copy.getSequence() == ps_initial.getSequence()); // Проверяем, что последовательности совпадают

    // Тестирование оператора присваивания
    ProteinSequence ps_assign;
    ps_assign = ps_initial;
    assert(ps_assign.getSequence() == "ACD"); // Проверяем, что последовательность правильная после присваивания

    // Тестирование идентификации
    assert(ps_default.identify() == "Родительский класс белковой последовательности");
    assert(ps_initial.identify() == "Родительский класс белковой последовательности");

    // Тестирование класса ExtendedProteinSequence
    ExtendedProteinSequence nucleotideSeq;
    nucleotideSeq.synthesizeFromNucleotides("AUGUUUCUU"); // MFL

    assert(nucleotideSeq.getSequence() == "MFL"); // Проверяем, что последовательность правильная

    // Тестирование идентификации для класса-наследника
    assert(nucleotideSeq.identify() == "Класс наследуемый от Protein Sequence");

    // Вывод сообщения об успешном прохождении тестов
    cout << "Все тесты пройдены успешно!" << endl;

    return 0;
}
