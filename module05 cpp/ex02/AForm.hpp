#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>

class Bureaucrat;


class	AForm{
    private:
		const std::string _name;
        bool _signed;
        const int _gradeSign;
        const int _gradeExecute;
	public:
		AForm();
		AForm(const std::string &name, int gradeSign, int gradeExecute);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		virtual ~AForm();


		std::string getName() const;
		bool getIsSigned() const;
		int	getRequiredToSign() const;
		int getRequiredToExecute() const;

		void beSigned(const Bureaucrat& b);


		virtual void execute(Bureaucrat const & executor) const;
		virtual void performAction() const = 0;

		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw()
				{
					return "Grade is too high";
				}
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw()
				{
					return "Grade is too low";
				}
		};

		class FormNotSignedException : public std::exception
		{
			public:
				const char* what() const throw()
				{
					return "Form is not signed";
				}
		};
};

std::ostream& operator<<(std::ostream& out, const AForm& f);

#endif