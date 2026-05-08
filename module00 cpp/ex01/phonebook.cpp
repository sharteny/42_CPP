#include "phonebook.hpp"

void PhoneBook::add()
{
    std::string fn, ln, nn, pn, sec;
    std::cout << "\033[95m\n✎ Enter the contact information ✎\033[0m\n" << std::endl;
    std::cout << "First Name     : ";
    std::getline(std::cin, fn);
    std::cout << "Last Name      : ";
    std::getline(std::cin, ln);
    std::cout << "Nickname       : ";
    std::getline(std::cin, nn);
    std::cout << "Phone Number   : ";
    std::getline(std::cin, pn);
    std::cout << "Darkest Secret : ";
    std::getline(std::cin, sec);

    if (fn.empty() || ln.empty() || nn.empty()
        || pn.empty() || sec.empty())
    {
        std::cout << "\033[31m✘ Fields cannot be empty!\033[0m\n" << std::endl;
        return;
    }
    contacts[index].setcontent(fn, ln, nn, pn, sec);
    if (count < 8)
        count++;
    index++;
    if (index == 8)
        index = 0;

    std::cout << "\033[32m✓ Contact successfully saved!\033[0m\n" << std::endl;
}

int PhoneBook::ask_index()
{
    int index;

    while (1)
    {
        std::cout << "\033[96mEnter index : \033[0m";

        std::cin >> index;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(10000, '\n');

            std::cout << "\033[31m✘ Give me a valid integer!\033[0m" << std::endl;
        }
        else if (index < 0 || index >= this->count)
        {
            std::cout << "\033[31m✘ Invalid index!\033[0m" << std::endl;
        }
        else
        {
            std::cin.ignore(10000, '\n');
            break;
        }
    }

    return (index);
}

void PhoneBook::search()
{
    std::cout << "\n\033[95m📒 PHONEBOOK DIRECTORY 📒\033[0m" << std::endl;

    std::cout << "-------------------------------------------------" << std::endl;
    std::cout << "|      Index|First Name| Last Name|  Nickname|" << std::endl;
    std::cout << "-------------------------------------------------" << std::endl;

    if (count == 0)
    {
        std::cout << "\033[31mPhoneBook is empty.\033[0m\n" << std::endl;
        return;
    }

    for (int i = 0; i < count; i++)
        contacts[i].sortprint(i);

    int index = ask_index();

    contacts[index].fullprint();
}

PhoneBook::PhoneBook(){
    index = 0;
    count = 0;

}