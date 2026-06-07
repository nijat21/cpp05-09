#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {

	std::cout << "Creating bureaucrats with proper grades" << std::endl;
	std::cout << "-------------------------------------------------------------" << std::endl;
	Bureaucrat a("John", 150);
	std::cout << a << std::endl;
	Bureaucrat b("Bela", 1);
	std::cout << b << std::endl;
	std::cout << "-------------------------------------------------------------\n" << std::endl;
	std::cout << "Creating forms" << std::endl;
	std::cout << "-------------------------------------------------------------" << std::endl;
	Form tax("tax", 1, 2);
	std::cout << tax << std::endl;
	std::cout << "-------------------------------------------------------------\n" << std::endl;
	std::cout << "Sign the form" << std::endl;
	std::cout << "-------------------------------------------------------------" << std::endl;
	a.signForm(tax);
	b.signForm(tax);
	/* Another option would be rethrowing the same error in signForm method 
	 * and using try catch block here as well */
	/* try { */
	/* 	b.signForm(tax); */
	/* 	a.signForm(tax); */
	/* } */ 
	/* catch(const std::exception& e) { */
	/* 	std::cout << e.what() << std::endl; */
	/* } */
	
	return 0;
}
