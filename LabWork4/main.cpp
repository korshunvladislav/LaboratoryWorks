#include <iostream>
#include <cassert>
#include "WordCollection.h"

int main() {
    WordCollection wc;
    assert(wc.size() == 0);

    wc.add("apple");
    assert(wc.size() == 1);
    wc.add("banana");
    assert(wc.size() == 2);
    wc.add("apple");
    assert(wc.size() == 2);

    wc.add("grape");
    assert(wc.size() == 3);
    wc.remove("banana");
    assert(wc.size() == 2);

    wc.clear();
    assert(wc.size() == 0);

    WordCollection emptyCollection;
    WordCollection result = wc && emptyCollection;
    assert(result.size() == 0);

    wc.add("apple");
    wc.add("grape");
    WordCollection result2 = wc && wc;
    assert(result2.size() == wc.size());
    assert(result2["apple"] == wc["apple"]);
    assert(result2["grape"] == wc["grape"]);

    WordCollection wcCopy = wc;
    assert(wc == wcCopy);
    wc.add("orange");
    assert(!(wc == wcCopy));

    wc.saveToFile("test_words.txt");
    WordCollection wcLoaded;
    wcLoaded.loadFromFile("test_words.txt");
    assert(wc == wcLoaded);

    std::cout << "All tests passed successfully!" << std::endl;
    return 0;
}
