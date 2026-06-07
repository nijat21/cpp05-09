#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

AForm::AForm(const std::string& name, int signGrade, int execGrade)
    : name(name), _signed(false), signGrade(signGrade), execGrade(execGrade) {}

AForm::AForm(const AForm &src)
    : name(src.name), _signed(src._signed), signGrade(src.signGrade), execGrade(src.execGrade) {}

AForm &AForm::operator=(const AForm &rhs) {
    if (this != &rhs)
        _signed = rhs.getStatus();
    return (*this);
}

AForm::~AForm() {}

const std::string AForm::getName() const {
    return name;
}

bool AForm::getStatus() const {
    return _signed;
}

int AForm::getSignGrade() const {
    return signGrade;
}

int AForm::getExecGrade() const {
    return execGrade;
}

void AForm::beSigned(const Bureaucrat &b) {
    if (b.getGrade() > signGrade)
        throw GradeTooLowException();
    else
        _signed = true;
}

void AForm::checkExecReq(const Bureaucrat& b) const {
	if(b.getGrade() > execGrade)
		throw GradeTooLowException();
}

const char *AForm::GradeTooHighException::what() const throw() {
    return "Grade is too high!";
}

const char *AForm::GradeTooLowException::what() const throw() {
    return "Grade is too low!";
}

std::ostream &operator<<(std::ostream &out, const AForm &f) {
    out << f.getName() << "; is " << (f.getStatus() ? "signed" : "not signed")
        << "; with signGrade: " << f.getSignGrade() << "; and execGrade: " << f.getExecGrade()
        << ";";
    return out;
}
