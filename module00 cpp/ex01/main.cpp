#include "contact.hpp"
#include "phonebook.hpp"

int main()
{
    PhoneBook dir;
    std::string action;

    std::cout << "\033[95m☏ Welcome to My Awesome PhoneBook ☏\033[0m\n" << std::endl;

    while (1)
    {
        std::cout << "\033[96mChoose a command:\033[0m ";
        std::cout << "[ADD] [SEARCH] [EXIT]\n> ";

        if (!std::getline(std::cin, action))
        {
            if (std::cin.eof())
                break;
        }

        std::cout << std::endl;

        if (action == "ADD")
            dir.add();

        else if (action == "SEARCH")
            dir.search();

        else if (action == "EXIT")
        {
            std::cout << "\n\033[95m Thank you for using My Awesome PhoneBook!\033[0m" << std::endl;
            break;
        }

        else
        {
            std::cout << "\033[31m✘ Unknown command.\033[0m\n" << std::endl;
        }
    }

    return (0);
}