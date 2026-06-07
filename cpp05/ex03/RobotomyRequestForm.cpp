#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("RobotomyRequestForm", 72, 45), target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src)
    : AForm(src), target(src.target) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs) {
    if (this != &rhs) {
        target = rhs.target;
        AForm::operator=(rhs);
    }
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(const Bureaucrat &b) const {
    checkExecReq(b);
    std::srand(time(0));
    if (std::rand() % 2)
        std::cout << target << " has been robotomized successfully\n";
    else
        std::cout << "Robotomy failed\n";
}
