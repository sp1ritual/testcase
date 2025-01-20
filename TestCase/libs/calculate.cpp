#include <iostream>
#include </Users/admi/Documents/TestCase/include/calculate.h>
#include <algorithm>
#include <string>

void sorting(const std::string& input) {
    //отсортировать в порядке убывания
    std::string sortedInput = input;
    std::sort(sortedInput.begin(), sortedInput.end(), std::greater<char>());
    std::string stirng_result;
    for (size_t i = 0; i < sortedInput.size(); i++) {
        //если число четное вместо него добавить символ КВ
        if (i % 2 == 0) {
            stirng_result += "KB"; 
        } else {
            stirng_result += sortedInput[i]; 
        }
    }

    // Выводим результат
    std::cout << stirng_result;
}
int calulcateANDreturn(const std::string& input){
    int result=0;
    for (int i=0;i<input.size();i++){
         if (std::isdigit(input[i])){ // если символ цифровой тогда прибавить его к сумме имеющихся
            result+=input[i] - '0';
         }
    }
    return result;
    std::cout << result << std::endl;
};
bool countOfsymbols(const std::string& input){
    if (input.length()>2 && input.size() % 32 == 0){
        return true;
    } else
    {
        return false;
    }
};

