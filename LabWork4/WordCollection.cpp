#include "WordCollection.h"
#include <iostream>
#include <fstream>
#include <sstream>

WordCollection::WordCollection() {}

WordCollection::WordCollection(const WordCollection& other)
        : wordCountMap(other.wordCountMap) {}

WordCollection::~WordCollection() {}

void WordCollection::clear() {
    wordCountMap.clear();
}

size_t WordCollection::size() const {
    return wordCountMap.size();
}

void WordCollection::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file) {
        std::cerr << "Error opening file for writing: " << filename << std::endl;
        return;
    }
    for (const auto& pair : wordCountMap) {
        file << pair.first << " " << pair.second << "\n";
    }
    file.close();
}

void WordCollection::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error opening file for reading: " << filename << std::endl;
        return;
    }

    std::string word;
    size_t count;
    while (file >> word >> count) {
        wordCountMap[word] = count;
    }
    file.close();
}

bool WordCollection::operator==(const WordCollection& other) const {
    return wordCountMap == other.wordCountMap;
}

WordCollection& WordCollection::operator<<(const std::string& word) {
    add(word);
    return *this;
}

void WordCollection::add(const std::string& word) {
    wordCountMap[word]++;
}

void WordCollection::remove(const std::string& word) {
    auto it = wordCountMap.find(word);
    if (it != wordCountMap.end()) {
        wordCountMap.erase(it);
    }
}

size_t WordCollection::operator[](const std::string& word) const {
    auto it = wordCountMap.find(word);
    if (it != wordCountMap.end()) {
        return it->second;
    }
    return 0;
}

bool WordCollection::exists(const std::string& word) const {
    return wordCountMap.find(word) != wordCountMap.end();
}

WordCollection WordCollection::operator&&(const WordCollection& other) const {
    WordCollection commonWords;
    for (const auto& pair : wordCountMap) {
        if (other.exists(pair.first)) {
            commonWords.add(pair.first);
        }
    }
    return commonWords;
}

size_t WordCollection::countWordsWithMinRepeats(const size_t minRepeats) const {
    size_t count = 0;
    for (const auto& pair : wordCountMap) {
        if (pair.second >= minRepeats) {
            count++;
        }
    }
    return count;
}
