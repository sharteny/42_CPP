#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
    std::srand(std::time(NULL));

    std::cout << "===== TEST 1: Shrubbery =====" << std::endl;

    Bureaucrat bob("Bob", 130);
    ShrubberyCreationForm shrub("home");

    std::cout << shrub << std::endl;

    bob.signForm(shrub);

    std::cout << shrub << std::endl;

    bob.executeForm(shrub);


    std::cout << std::endl;
    std::cout << "===== TEST 2: Robotomy =====" << std::endl;

    Bureaucrat robotBoss("RobotBoss", 40);
    RobotomyRequestForm robot("Bender");

    robotBoss.signForm(robot);
    robotBoss.executeForm(robot);


    std::cout << std::endl;
    std::cout << "===== TEST 3: Presidential Pardon =====" << std::endl;

    Bureaucrat president("President", 1);
    PresidentialPardonForm pardon("Arthur Dent");

    president.signForm(pardon);
    president.executeForm(pardon);


    std::cout << std::endl;
    std::cout << "===== TEST 4: Execute unsigned form =====" << std::endl;

    Bureaucrat boss("Boss", 1);
    ShrubberyCreationForm unsignedForm("garden");

    boss.executeForm(unsignedForm);


    std::cout << std::endl;
    std::cout << "===== TEST 5: Grade too low =====" << std::endl;

    Bureaucrat lowGrade("LowGrade", 150);
    ShrubberyCreationForm form("tree");

    lowGrade.signForm(form);
    lowGrade.executeForm(form);


    std::cout << std::endl;
    std::cout << "===== TEST 6: Sign but cannot execute =====" << std::endl;

    Bureaucrat signer("Signer", 100);
    ShrubberyCreationForm shrub2("park");

    signer.signForm(shrub2);
    signer.executeForm(shrub2);

    return 0;
}