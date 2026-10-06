#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    std::cout << "========== FORM CREATION ==========" << std::endl;

    try
    {
        Form form1("Tax Form", 50, 30);

        std::cout << form1 << std::endl;
        std::cout << "Name: " << form1.getName() << std::endl;
        std::cout << "Signed: " << form1.getIsSigned() << std::endl;
        std::cout << "Sign grade: " << form1.getGradeSign() << std::endl;
        std::cout << "Execute grade: " << form1.getGradeExecute() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }


    std::cout << std::endl;
    std::cout << "========== INVALID GRADES ==========" << std::endl;

    try
    {
        Form form2("Too High", 0, 50);
        std::cout << form2 << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try
    {
        Form form3("Too Low", 151, 50);
        std::cout << form3 << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try
    {
        Form form4("Bad Execute Grade", 50, 0);
        std::cout << form4 << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try
    {
        Form form5("Bad Execute Grade", 50, 151);
        std::cout << form5 << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }


    std::cout << std::endl;
    std::cout << "========== SIGNING ==========" << std::endl;

    try
    {
        Bureaucrat boss("Boss", 20);
        Form form("Important Form", 50, 30);

        std::cout << boss << std::endl;
        std::cout << form << std::endl;

        boss.signForm(form);

        std::cout << form << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }


    std::cout << std::endl;
    std::cout << "========== SIGNING FAILED ==========" << std::endl;

    try
    {
        Bureaucrat intern("Intern", 100);
        Form form("Boss Form", 50, 30);

        std::cout << intern << std::endl;
        std::cout << form << std::endl;

        intern.signForm(form);

        std::cout << form << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }


    std::cout << std::endl;
    std::cout << "========== EXACT GRADE ==========" << std::endl;

    try
    {
        Bureaucrat bureaucrat("John", 50);
        Form form("Exact Grade Form", 50, 30);

        bureaucrat.signForm(form);

        std::cout << form << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}