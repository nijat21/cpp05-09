#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <string>

Intern::Intern() {}

Intern::Intern(const Intern &src) {
    *this = src;
}

Intern &Intern::operator=(const Intern &rhs) {
    if (this != &rhs) {
    }
    return (*this);
}

Intern::~Intern() {}

AForm *Intern::makeForm(const std::string &formName, const std::string &target) {
    AForm* res = NULL;
    switch (formName[0]) {
        case 'S':
            if (formName == "ShrubberyCreationForm")
                res = new ShrubberyCreationForm(target);
            break;
        case 'R':
            if (formName == "RobotomyRequestForm")
                res = new RobotomyRequestForm(target);
            break;
        case 'P':
            if (formName == "PresidentialPardonForm")
                res = new PresidentialPardonForm(target);
            break;
        default:
            break;
    }
    if(res) 
        std::cout << "Intern creates " << formName << std::endl;
    else
        std::cerr << "There's not such form" << std::endl;
    return res;
}
