#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include <string>
#include "contact.hpp"

class PhoneBook {
    private:
        Contact contacts[8];
        int index; 
        int count;
    public:
        PhoneBook();
        void add();
        void search();
        int ask_index();
        
};


#endif