#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <iomanip>

class Contact {
    private:
        std::string firstname;
        std::string lastname;
        std::string nickname;
        std::string phonenumber;
        std::string darkestsecret;
    public:
        void setcontent(std::string name, std::string last, std::string nick, std::string phone, std::string secret);
        std::string cutString(std::string str);
        void sortprint(int index);
        void fullprint();

};

#endif