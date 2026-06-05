#include "Bureaucrat.hpp"
#include <string>
#include <iostream>

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
	    grade = rhs.grade;
    }
    return (*this);
}

Bureaucrat::~Bureaucrat(){
}

std::string Bureaucrat::getName() const {
	return name;
}

int Bureaucrat::getGrade() const {
	return grade;
}

void Bureaucrat::incrementGrade() {
	std::cout << "Incrementing grade of " << name << std::endl;
	if(grade - 1 < 1)
		throw GradeTooHighException();
	grade--; 
}

void Bureaucrat::decrementGrade() {
	std::cout << "Decrementing grade of " << name << std::endl;
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

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b) {
	out << b.getName() << ", bureaucrat grade " << b.getGrade();
	return out;
}

