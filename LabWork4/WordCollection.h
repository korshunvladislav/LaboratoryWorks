#ifndef WORDCOLLECTION_H
#define WORDCOLLECTION_H

#include <string>
#include <unordered_map>

class WordCollection {
public:
    WordCollection();

    WordCollection(const WordCollection& other);

    ~WordCollection();

    void clear();

    size_t size() const;

    void saveToFile(const std::string& filename) const;

    void loadFromFile(const std::string& filename);

    bool operator==(const WordCollection& other) const;

    WordCollection& operator<<(const std::string& word);

    void add(const std::string& word);

    void remove(const std::string& word);

    size_t operator[](const std::string& word) const;

    bool exists(const std::string& word) const;

    WordCollection operator&&(const WordCollection& other) const;

    size_t countWordsWithMinRepeats(size_t minRepeats) const;

private:
    std::unordered_map<std::string, size_t> wordCountMap;
};

#endif