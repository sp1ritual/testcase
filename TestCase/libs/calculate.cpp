#include "calculate.h"
#include <algorithm>
#include <iostream>
#include <cctype>

Library::Library(const std::string& input) : input_(input) {}

void Library::sorting() const {
    std::string sortedInput = input_;
    std::sort(sortedInput.begin(), sortedInput.end(), std::greater<char>());

    std::string string_result;
    for (size_t i = 0; i < sortedInput.size(); i++) {
        if (i % 2 == 0) {
            string_result += "KB";
        } else {
            string_result += sortedInput[i];
        }
    }
    std::cout << string_result << std::endl;
}

int Library::calculateAndReturn() const {
    int result = 0;
    for (char c : input_) {
        if (std::isdigit(c)) {
            result += c - '0';
        }
    }
    return result;
}

bool Library::countOfSymbols() const {
    return input_.length() > 2 && input_.size() % 32 == 0;
}

// Экспортируемые функции
extern "C" {
    Library* createLibrary(const char* input) {
        return new Library(input);
    }

    void destroyLibrary(Library* obj) {
        delete obj;
    }

    void sorting(Library* obj) {
        obj->sorting();
    }

    int calculateAndReturn(Library* obj) {
        return obj->calculateAndReturn();
    }

    bool countOfSymbols(Library* obj) {
        return obj->countOfSymbols();
    }
}
