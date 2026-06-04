#include "Bureaucrat.hpp"
#include <string>

const char* Bureaucrat::GradeTooHighException::what() const throw();
const char* Bureaucrat::GradeTooLowException::what() const throw();

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name) {
	if(grade < 1)
		throw GradeTooHighException();
	else if(grade > 150)
		throw GradeTooLowException();
	this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src)
{
    *this = src;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs)
{
    if (this != &rhs)
    {
	    name = rhs.name;
	    grade = rhs.grade;
    }
    return (*this);
}

Bureaucrat::~Bureaucrat(){
}

std::string getName() const {
	return name;
}

int Bureaucrat::getGrade() const {
	return grade;
}

void Bureaucrat::incrementGrade() {
	if(grade - 1 < 1)
		throw GradeTooHighException();
	grade--; 
}

void Bureaucrat::decrementGrade() {
	if(grade + 1 > 150)
		throw GradeTooLowException();
	grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade is too low!";
}

