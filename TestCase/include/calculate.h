#ifndef CALCULATE_H
#define CALCULATE_H

#include <string>

class Library {
public:
    Library(const std::string& input);
    void sorting() const;
    int calculateAndReturn() const;
    bool countOfSymbols() const;

private:
    std::string input_;
};

// Экспортируемые функции для динамической библиотеки
extern "C" {
    Library* createLibrary(const char* input);
    void destroyLibrary(Library* obj);
    void sorting(Library* obj);
    int calculateAndReturn(Library* obj);
    bool countOfSymbols(Library* obj);
}

#endif 