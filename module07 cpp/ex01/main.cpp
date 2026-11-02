
#include <iostream>
#include <string>
#include "iter.hpp"

void printInt(const int &n)
{
    std::cout << n << std::endl;
}

void increment(int &n)
{
    n++;
}

template <typename T>
void print(const T &value)
{
    std::cout << value << std::endl;
}

void toUpper(char &c)
{
    if (c >= 'a' && c <= 'z')
        c -= 32;
}

int main()
{
    // Test 1: Integer array
    std::cout << "===== Test 1: Integer array =====" << std::endl;
    int numbers[] = {1, 2, 3, 4, 5};

    std::cout << "--- Original values ---" << std::endl;
    ::iter(numbers, 5, printInt);

    std::cout << "--- After increment ---" << std::endl;
    ::iter(numbers, 5, increment);
    ::iter(numbers, 5, printInt);


    // Test 2: Double array
    std::cout << "\n===== Test 2: Double array =====" << std::endl;
    double decimals[] = {1.5, 2.5, 3.5};
    ::iter(decimals, 3, print<double>);


    // Test 3: String array
    std::cout << "\n===== Test 3: String array =====" << std::endl;
    std::string words[] = {"Hello", "World", "C++"};
    ::iter(words, 3, print<std::string>);


    // Test 4: Character array
    std::cout << "\n===== Test 4: Character array =====" << std::endl;
    char letters[] = {'a', 'b', 'c'};

    std::cout << "--- Original letters ---" << std::endl;
    ::iter(letters, 3, print<char>);

    std::cout << "--- Uppercase letters ---" << std::endl;
    ::iter(letters, 3, toUpper);
    ::iter(letters, 3, print<char>);


    // Test 5: Const array
    std::cout << "\n===== Test 5: Const array =====" << std::endl;
    const int fixed[] = {10, 20, 30};
    ::iter(fixed, 3, print<int>);


    // Test 6: Empty array
    std::cout << "\n===== Test 6: Empty array =====" << std::endl;
    ::iter(numbers, 0, printInt);
    std::cout << "Empty array test completed." << std::endl;

    return 0;
}
