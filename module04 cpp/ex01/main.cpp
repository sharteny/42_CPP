#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    std::cout << "\n===== BASIC TEST =====\n" << std::endl;

    const Animal* j = new Dog();
    const Animal* i = new Cat();

    delete j;
    delete i;

    std::cout << "\n===== ARRAY TEST (IMPORTANT) =====\n" << std::endl;

    Animal* animals[6];

    for (int k = 0; k < 3; k++)
        animals[k] = new Dog();

    for (int k = 3; k < 6; k++)
        animals[k] = new Cat();

    for (int k = 0; k < 6; k++)
        delete animals[k];

    std::cout << "\n===== DEEP COPY TEST =====\n" << std::endl;

    Dog a;
    Dog b = a;

    Dog c;
    c = a;

    std::cout << "\n===== END =====\n" << std::endl;

    return 0;
}