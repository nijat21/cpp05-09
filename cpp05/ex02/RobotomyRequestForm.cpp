#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
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

static void successSound() {
#if __APPLE__
    std::system("afplay ./audio/robotomize.mp3 &");
#else
    std::system("aplay ./audio/robotomize.mp3 &");
#endif
}

static void failureSound() {
#if __APPLE__
    std::system("afplay ./audio/sustained.mp3 &");
#else
    std::system("aplay ./audio/sustained.mp3 &");
#endif
}

void RobotomyRequestForm::execute(const Bureaucrat &b) const {
    checkExecReq(b);
    std::srand(time(0));
    if (std::rand() % 2) {
        std::cout << target << " has been robotomized successfully\n";
        successSound();
    } else {
        std::cout << "Robotomy failed\n";
        failureSound();
    }
}
