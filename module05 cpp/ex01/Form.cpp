#include "Form.hpp"

Form::Form()
    : _name("Default Form"),
      _signed(false),
      _gradeSign(150),
      _gradeExecute(150)
{
}

Form::Form(const std::string &name, int gradeSign, int gradeExecute)
    : _name(name),
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

Form::Form(const Form &other)
    : _name(other._name),
      _signed(other._signed),
      _gradeSign(other._gradeSign),
      _gradeExecute(other._gradeExecute)
{
}

Form &Form::operator=(const Form &other)
{
    if (this != &other)
        _signed = other._signed;
    return *this;
}

Form::~Form()
{
}

const std::string &Form::getName() const
{
    return _name;
}

bool Form::getIsSigned() const
{
    return _signed;
}

int Form::getGradeSign() const
{
    return _gradeSign;
}

int Form::getGradeExecute() const
{
    return _gradeExecute;
}

void Form::beSigned(const Bureaucrat &b)
{
    if (b.getGrade() > _gradeSign)
        throw GradeTooLowException();

    _signed = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
    return "Form grade is too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "Form grade is too low";
}

std::ostream &operator<<(std::ostream &out, const Form &f)
{
    out << "Form: " << f.getName()
        << ", signed: " << (f.getIsSigned() ? "yes" : "no")
        << ", sign grade: " << f.getGradeSign()
        << ", execute grade: " << f.getGradeExecute();
    return out;
}