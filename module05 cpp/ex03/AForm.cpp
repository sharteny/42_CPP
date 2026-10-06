#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() :
    _name("Default Form"),
    _signed(false),
    _gradeSign(150),
    _gradeExecute(150)
{}

AForm::AForm(const std::string &name, int gradeSign, int gradeExecute): 
    _name(name),
    _signed(false),
    _gradeSign(gradeSign),
    _gradeExecute(gradeExecute)
{
    if (gradeSign < 1)
        throw GradeTooHighException();
    if (gradeSign > 150)
        throw GradeTooLowException();

    if (gradeExecute < 1)
        throw GradeTooHighException();
    if (gradeExecute > 150)
        throw GradeTooLowException();
}


AForm::AForm(const AForm& other)
    : _name(other._name),
      _signed(other._signed),
      _gradeSign(other._gradeSign),
      _gradeExecute(other._gradeExecute)
{
}

AForm& AForm::operator=(const AForm& other)
{
    if (this != &other)
        _signed = other._signed;
    return *this;
}

AForm::~AForm()
{}


std::string AForm::getName() const
{
	return _name;
}

bool AForm::getIsSigned() const
{
	return _signed;
}

int	AForm::getRequiredToSign() const
{
	return _gradeSign;
}

int AForm::getRequiredToExecute() const
{
	return _gradeExecute;
}


void AForm::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() > this->_gradeSign)
		throw GradeTooLowException();
	this->_signed = true;
}


void AForm::execute(Bureaucrat const & executor) const
{
	if (!this->_signed)
		throw FormNotSignedException();
	if (executor.getGrade() > this->_gradeExecute)
		throw GradeTooLowException();
	performAction();

}


std::ostream& operator<<(std::ostream& out, const AForm& f)
{
	out << "AForm: "<< f.getName() << ", signed: " << (f.getIsSigned() ? "yes" : "no")
	<< ", required to sign: " << f.getRequiredToSign()
	<< ", required to execute: " << f.getRequiredToExecute();
	return out;
}