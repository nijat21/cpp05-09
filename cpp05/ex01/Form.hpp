#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include <exception>

class Bureaucrat;

class Form
{
    public:
        Form(const std::string name, int signGrade, int execGrade);
        Form(const Form &src);
        Form &operator=(const Form &rhs);
        ~Form();

	const std::string getName() const;
	bool getStatus() const;
	int getSignGrade() const;
	int getExecGrade() const;
	void beSigned(const Bureaucrat& b);

	class GradeTooHighException : public std::exception {
		public:
			virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
		public:
			virtual const char* what() const throw();
	};

    private:
	const std::string name;
	bool _signed;
	const int signGrade;
	const int execGrade;
};

std::ostream& operator<<(std::ostream& out, const Form& f);
#endif
