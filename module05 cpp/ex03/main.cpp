#include "Intern.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

#include <iostream>

int main()
{
    Intern someRandomIntern;

    std::cout << "===== ROBOTOMY =====" << std::endl;

    AForm* rrf = someRandomIntern.makeForm(
        "robotomy request",
        "Bender"
    );

    if (rrf)
    {
        std::cout << *rrf << std::endl;

        Bureaucrat robotBoss("RobotBoss", 40);

        robotBoss.signForm(*rrf);
        robotBoss.executeForm(*rrf);

        delete rrf;
    }


    std::cout << std::endl;
    std::cout << "===== SHRUBBERY =====" << std::endl;

    AForm* shrub = someRandomIntern.makeForm(
        "shrubbery creation",
        "home"
    );

    if (shrub)
    {
        Bureaucrat gardener("Gardener", 130);

        gardener.signForm(*shrub);
        gardener.executeForm(*shrub);

        delete shrub;
    }


    std::cout << std::endl;
    std::cout << "===== PARDON =====" << std::endl;

    AForm* pardon = someRandomIntern.makeForm(
        "presidential pardon",
        "Arthur Dent"
    );

    if (pardon)
    {
        Bureaucrat president("President", 1);

        president.signForm(*pardon);
        president.executeForm(*pardon);

        delete pardon;
    }


    std::cout << std::endl;
    std::cout << "===== INVALID FORM =====" << std::endl;

    AForm* invalid = someRandomIntern.makeForm(
        "some random form",
        "Bender"
    );

    if (invalid)
        delete invalid;

    return 0;
}