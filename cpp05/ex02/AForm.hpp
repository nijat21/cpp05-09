#ifndef AFORM_HPP
#define AFORM_HPP

#include <exception>
#include <iostream>
#include <string>

class Bureaucrat;

class AForm {
  public:
    AForm(const std::string& name, int signGrade, int execGrade);
    AForm(const AForm &src);
    AForm &operator=(const AForm &rhs);
    ~AForm();

    const std::string getName() const;
    bool getStatus() const;
    int getSignGrade() const;
    int getExecGrade() const;
    void beSigned(const Bureaucrat &b);
    void checkExecReq(const Bureaucrat& b) const;

    virtual void execute(const Bureaucrat& b) const = 0;

    class GradeTooHighException : public std::exception {
      public:
        virtual const char *what() const throw();
    };

    class GradeTooLowException : public std::exception {
      public:
        virtual const char *what() const throw();
    };

  private:
    const std::string name;
    bool _signed;
    const int signGrade;
    const int execGrade;
};

std::ostream &operator<<(std::ostream &out, const AForm &f);

#endif
