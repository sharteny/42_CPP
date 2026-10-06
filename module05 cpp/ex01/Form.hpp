#ifndef FORM_HPP
#define FORM_HPP
#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class   Form{
    private:
        const std::string _name;
        bool _signed;
        const int _gradeSign;
        const int _gradeExecute;
    public:
        Form();
        Form(const std::string &name, int gradeSign, int gradeExecute);
        Form(const Form &other);
        Form &operator=(const Form &other);
        ~Form();

        const std::string& getName() const;
        bool getIsSigned() const;
        int getGradeSign() const;
        int getGradeExecute() const;

        void beSigned(const Bureaucrat &b);


	    class GradeTooHighException : public std::exception
	    {
	        public:
		        const char* what() const throw();
	    };

	    class GradeTooLowException : public std::exception
	    {
	        public:
		        const char* what() const throw();
	    };
};

std::ostream& operator<<(std::ostream& out, const Form& f);

#endif