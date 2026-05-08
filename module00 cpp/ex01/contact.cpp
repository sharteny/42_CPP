
#include "contact.hpp"

void Contact::setcontent(std::string name, std::string last, std::string nick, std::string phone, std::string secret){
    firstname = name;
    lastname = last;
    nickname = nick;
    phonenumber = phone;
    darkestsecret = secret;
}

std::string Contact::cutString(std::string str){
    std::string substring;

    if (str.length() > 10) {
        substring = str.substr(0, 9) + ".";
    }
    else
        return(str);
    return (substring);
}

void Contact::sortprint(int index)
{
    std::cout << "| " << std::setw(10) << std::right << index<< "| "
    << std::setw(10) << std::right << cutString(firstname) << "| "
    << std::setw(10) << std::right << cutString(lastname) << "| "
    << std::setw(10) << std::right << cutString(nickname) << "|\n";
}

void Contact::fullprint()
{
    std::cout << "\n";
    std::cout << "\033[95m";
    std::cout << "╔══════════════ ☏ CONTACT ☏ ══════════════╗";
    std::cout << "\033[0m\n" << std::endl;

    std::cout << "  First Name      : " << firstname << std::endl;
    std::cout << "  Last Name       : " << lastname << std::endl;
    std::cout << "  Nickname        : " << nickname << std::endl;
    std::cout << "  Phone Number    : " << phonenumber << std::endl;
    std::cout << "  Darkest Secret  : " << darkestsecret << std::endl;

    std::cout << "\n";
    std::cout << "\033[95m";
    std::cout << "╚══════════════════════════════════════════╝";
    std::cout << "\033[0m\n" << std::endl;
}
