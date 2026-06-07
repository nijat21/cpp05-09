#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <string>

class RobotomyRequestForm : public AForm {
  public:
    RobotomyRequestForm(const std::string &target);
    RobotomyRequestForm(const RobotomyRequestForm &src);
    RobotomyRequestForm &operator=(const RobotomyRequestForm &rhs);
    ~RobotomyRequestForm();

    void execute(const Bureaucrat &b) const;

  private:
    std::string target;
};

#endif
