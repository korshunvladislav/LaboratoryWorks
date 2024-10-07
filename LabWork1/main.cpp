#include <iostream>
#include <vector>
#include <cassert>
#include "AminoAcid.h"
#include "ProteinSequence.h"

using namespace std;

int main() {
    ProteinSequence seq1;
    seq1.addCodon("AUG"); // M (метионин)
    seq1.addCodon("UUU"); // F (фенилаланин)
    seq1.addCodon("CUU"); // L (лейцин)

    ProteinSequence seq2;
    seq2.addCodon("UUU"); // F
    seq2.addCodon("CUC"); // L
    seq2.addCodon("GUC"); // V (валин)

    ProteinSequence mergedSeq = ProteinSequence::merge(seq1, seq2);

    cout << "Объединенная последовательность: " << mergedSeq.getSequence() << endl;

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

    // Вывод сообщения об успешном прохождении тестов
    cout << "Все тесты пройдены успешно!" << endl;

    return 0;
}
