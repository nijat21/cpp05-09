#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

int main() {

	std::cout << "===============================================================================" << std::endl;
	std::cout << "Creating bureaucrats with proper grades" << std::endl;
	std::cout << "===============================================================================" << std::endl;
	Bureaucrat a("Arthur", 72);
	std::cout << a << std::endl;

	Bureaucrat b("Ford", 1);
	std::cout << b << std::endl;
	
	Bureaucrat c("Marvin", 140);
	std::cout << c << std::endl;
	std::cout << std::endl;

	std::cout << "===============================================================================" << std::endl;
	std::cout << "Creating Forms" << std::endl;
	std::cout << "===============================================================================" << std::endl;
	ShrubberyCreationForm s("home");
	std::cout << s << std::endl;
	std::cout << std::endl;

	RobotomyRequestForm r("electronic thumb");
	std::cout << r << std::endl;
	std::cout << std::endl;
	
	PresidentialPardonForm p("travelers");
	std::cout << s << std::endl;
	std::cout << std::endl;

	std::cout << "===============================================================================" << std::endl;
	std::cout << "Sign and Execute Forms: " << std::endl;
	std::cout << "===============================================================================" << std::endl;
	std::cout << s.getName() << std::endl;
	std::cout << "-------------------------------------------------------------------------------" << std::endl;
	a.signForm(s);
	a.executeForm(s);
	std::cout << std::endl;

	b.signForm(s);
	b.executeForm(s);
	std::cout << std::endl;

	c.signForm(s);
	c.executeForm(s);
	std::cout << std::endl;

	std::cout << r.getName() << std::endl;
	std::cout << "-------------------------------------------------------------------------------" << std::endl;
	a.signForm(r);
	a.executeForm(r);
	std::cout << std::endl;

	b.signForm(r);
	b.executeForm(r);
	std::cout << std::endl;

	c.signForm(r);
	c.executeForm(r);
	std::cout << std::endl;

	std::cout << p.getName() << std::endl;
	std::cout << "-------------------------------------------------------------------------------" << std::endl;
	a.signForm(p);
	a.executeForm(p);
	std::cout << std::endl;

	b.signForm(p);
	b.executeForm(p);
	std::cout << std::endl;

	c.signForm(p);
	c.executeForm(p);
	std::cout << std::endl;

	std::cout << "-------------------------------------------------------------------------------" << std::endl;
    
	std::cout << c.getName() << ":\nWith all the intellect of the universe running in my circuits,\n" <<
		"I have the lowest rank :(\nCan you believe it?\nI hate my life!" << std::endl;

	return 0;
}
