// #include "Array.hpp"

// #define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;//
//     return 0;
// }


#include <iostream>
#include <string>
#include "Array.hpp"

int main()
{
    // TEST 1: Empty array
    std::cout << "\n===== TEST 1: Empty array =====" << std::endl;

    Array<int> empty;

    std::cout << "Size: " << empty.size() << std::endl;

    // TEST 2: Default initialization
    std::cout << "\n===== TEST 2: Default initialization =====" << std::endl;

    Array<int> numbers(5);

    for (unsigned int i = 0; i < numbers.size(); i++)
        std::cout << "numbers[" << i << "] = " << numbers[i] << std::endl;

    // TEST 3: Modify elements
    std::cout << "\n===== TEST 3: Modify elements =====" << std::endl;

    for (unsigned int i = 0; i < numbers.size(); i++)
        numbers[i] = (i + 1) * 10;

    for (unsigned int i = 0; i < numbers.size(); i++)
        std::cout << numbers[i] << std::endl;

    // TEST 4: Copy constructor
    std::cout << "\n===== TEST 4: Copy constructor =====" << std::endl;

    Array<int> copy(numbers);

    copy[0] = 999;

    std::cout << "Original[0]: " << numbers[0] << std::endl;
    std::cout << "Copy[0]: " << copy[0] << std::endl;

    // TEST 5: Assignment operator
    std::cout << "\n===== TEST 5: Assignment operator =====" << std::endl;

    Array<int> assigned(2);

    assigned = numbers;
    assigned[1] = 888;

    std::cout << "Original[1]: " << numbers[1] << std::endl;
    std::cout << "Assigned[1]: " << assigned[1] << std::endl;
    std::cout << "Assigned size: " << assigned.size() << std::endl;

    // TEST 6: Self-assignment
    std::cout << "\n===== TEST 6: Self-assignment =====" << std::endl;

    numbers = numbers;

    for (unsigned int i = 0; i < numbers.size(); i++)
        std::cout << numbers[i] << std::endl;

    // TEST 7: String array
    std::cout << "\n===== TEST 7: String array =====" << std::endl;

    Array<std::string> words(3);

    words[0] = "Hello";
    words[1] = "World";
    words[2] = "C++";

    for (unsigned int i = 0; i < words.size(); i++)
        std::cout << words[i] << std::endl;

    // TEST 8: Const array
    std::cout << "\n===== TEST 8: Const array =====" << std::endl;

    const Array<int> fixed(numbers);

    std::cout << fixed[0] << std::endl;
    std::cout << fixed[1] << std::endl;

    // TEST 9: Out of bounds - negative index
    std::cout << "\n===== TEST 9: Negative index =====" << std::endl;

    try
    {
        numbers[-1] = 100;
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    // TEST 10: Out of bounds - too large index
    std::cout << "\n===== TEST 10: Index too large =====" << std::endl;

    try
    {
        numbers[5] = 100;
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    // TEST 11: Zero-size array
    std::cout << "\n===== TEST 11: Zero-size array =====" << std::endl;

    Array<int> zero(0);

    std::cout << "Size: " << zero.size() << std::endl;

    try
    {
        zero[0] = 10;
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n===== ALL TESTS COMPLETED =====" << std::endl;

    return 0;
}