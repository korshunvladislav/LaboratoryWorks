#include <iostream>
#include "ProteinSequence.h"

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

    std::cout << "Объединенная последовательность: " << mergedSeq.getSequence() << std::endl;

    return 0;
}
