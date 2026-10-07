#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

Form::Form(const std::string name, int signGrade, int execGrade)
    : name(name), _signed(false), signGrade(signGrade), execGrade(execGrade) {}

Form::Form(const Form &src)
    : name(src.name), _signed(src._signed), signGrade(src.signGrade), execGrade(src.execGrade) {}

Form &Form::operator=(const Form &rhs) {
    if (this != &rhs)
        _signed = rhs.getStatus();
    return (*this);
}

Form::~Form() {}

const std::string Form::getName() const {
    return name;
}

bool Form::getStatus() const {
    return _signed;
}

int Form::getSignGrade() const {
    return signGrade;
}

int Form::getExecGrade() const {
    return execGrade;
}

void Form::beSigned(const Bureaucrat &b) {
    if (b.getGrade() > signGrade)
        throw GradeTooLowException();
    else
        _signed = true;
}

const char *Form::GradeTooHighException::what() const throw() {
    return "Grade is too high!";
}

const char *Form::GradeTooLowException::what() const throw() {
    return "Grade is too low!";
}

std::ostream &operator<<(std::ostream &out, const Form &f) {
    out << "Form: '" << f.getName() << "' is '" << (f.getStatus() ? "SIGNED" : "NOT YET SIGNED")
        << "' with signGrade: " << f.getSignGrade() << " and execGrade: " << f.getExecGrade()
        << ".";
    return out;
}
