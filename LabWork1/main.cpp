#include <cassert>
#include "../LabWork3/Protein.h"

using namespace std;

int main() {
    Protein proteinA("ACDEFGH");
    Protein proteinB("FGHIKLM");

    assert(proteinA.getSequence() == "ACDEFGH");
    assert(proteinB.getSequence() == "FGHIKLM");

    Protein proteinC = proteinA + proteinB;

    assert(proteinC.getSequence() == "ACDEFGHIKLM");

    cout << "Protein A: " << proteinA << endl;
    cout << "Protein B: " << proteinB << endl;
    cout << "Protein C (A + B): " << proteinC << endl;

    cout << "Все тесты пройдены успешно!" << endl;
    return 0;
}
