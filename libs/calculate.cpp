#include <iostream>
#include <calculate.h>
#include <algorithm>
#include <string>

void sorting(const std::string& input) {
    //отсортировать в порядке убывания
    std::string sortedInput = input;
    std::sort(sortedInput.begin(), sortedInput.end(), std::greater<char>());
    std::string result;
    for (size_t i = 0; i < sortedInput.size(); i++) {
        //если число четное вместо него добавить символ КВ
        if (i % 2 == 0) {
            result += "KB"; 
        } else {
            result += sortedInput[i]; 
        }
    }

    // Выводим результат
    std::cout << result;
}
