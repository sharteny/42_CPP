#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
    try
    {
        Bureaucrat bob("Bob", 50);

        std::cout << bob << std::endl;

        bob.incrementGrade();
        std::cout << bob << std::endl;

        bob.decrementGrade();
        std::cout << bob << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }


    try
    {
        Bureaucrat bad("Bad", 0);
        std::cout << bad << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }


    try
    {
        Bureaucrat bad2("Bad2", 151);
        std::cout << bad2 << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }


    try
    {
        Bureaucrat high("High", 1);
        high.incrementGrade();
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }


    try
    {
        Bureaucrat low("Low", 150);
        low.decrementGrade();
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}