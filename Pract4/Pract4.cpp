#include <Windows.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <random>

void reverse(std::string& word) {
    std::reverse(word.begin(), word.end());
    std::cout << "Слово задом наперед: " << word << std::endl;
}

void removeVowels(const std::string& word) {
    std::string result = word;
    result.erase(std::remove_if(result.begin(), result.end(), [](char c) {
        return std::string("аеёиоуыэюяАЕЁИОУЫЭЮЯaeiouAEIOU").find(c) != std::string::npos;
        }), result.end());
    std::cout << "Слово без гласных: " << result << std::endl;
}

void removeConsonants(const std::string& word) {
    std::string result = word;
    result.erase(std::remove_if(result.begin(), result.end(), [](char c) {
        return std::string("бвгджзйклмнпрстфхцчшщьъБВГДЖЗЙКЛМНПРСТФХЦЧШЩЬЪbcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ").find(c) != std::string::npos;
        }), result.end());
    std::cout << "Слово без согласных: " << result << std::endl;
}

void shuffle(std::string& word) {
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(word.begin(), word.end(), g);
    std::cout << "Перемешанное слово: " << word << std::endl;
}

int main() {
    
    SetConsoleCP(1251);
    setlocale(0, "");
    std::string word;
    int choice = -1;
    std::cout << "Добро пожаловать в словарный интегратор! При введении в консоль 0 программа закончится.\n";
    while (choice != 0) {       
        std::cout << "Введите слово: ";
        std::cin >> word;

        if (word == "0") {
            break;
        }
        std::cout << "Выберите действие:" << std::endl;
        std::cout << "1. Слово задом наперед" << std::endl;
        std::cout << "2. Слово без гласных" << std::endl;
        std::cout << "3. Слово без согласных" << std::endl;
        std::cout << "4. Раскиданые буквы слова" << std::endl;
        std::cout << "Введите номер действия: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            reverse(word);
            break;
        case 2:
            removeVowels(word);
            break;
        case 3:
            removeConsonants(word);
            break;
        case 4:
            shuffle(word);
            break;
        default:
            std::cout << "Неверный выбор" << std::endl;
        }
    }
    return 0;
}