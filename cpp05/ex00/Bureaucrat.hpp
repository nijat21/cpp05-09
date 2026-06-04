#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string> 
#include <exception>

class Bureaucrat {
	public:
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat &src);
		Bureaucrat &operator=(const Bureaucrat &rhs);
		~Bureaucrat();


		std::string getName() const;
		int getGrade() const;

		void incrementGrade();
		void decrementGrade();

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
		int grade;
};

#endif
