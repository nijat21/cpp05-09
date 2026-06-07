#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include <string>
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("PresidentialPardonForm", 25, 5), 
	target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) : AForm(src), target(src.target) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs) {
    if (this != &rhs) {
	    target = rhs.target;
	    AForm::operator=(rhs);
    }
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(const Bureaucrat& b) const {
	checkExecReq(b);
	std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

