#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include <string>

class Intern {
  public:
    Intern();
    Intern(const Intern &src);
    Intern &operator=(const Intern &rhs);
    ~Intern();

    AForm *makeForm(const std::string &formName, const std::string &target);
};

#endif
