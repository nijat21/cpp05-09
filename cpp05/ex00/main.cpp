#include "Bureaucrat.hpp"
#include <iostream>

int main() {

	std::cout << "Creating bureaucrats with proper grades" << std::endl;
	std::cout << "-------------------------------------------------------------" << std::endl;
	Bureaucrat a("John", 150);
	std::cout << a << std::endl;
	Bureaucrat b("Bela", 1);
	std::cout << b << std::endl;
	std::cout << "-------------------------------------------------------------\n" << std::endl;
	std::cout << "Creating bureaucrats with wrong grades" << std::endl;
	std::cout << "-------------------------------------------------------------" << std::endl;
	try {
		Bureaucrat c("john", 151);
		std::cout << c << std::endl;
	} 
	catch(const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Bureaucrat d("john", 0);
		std::cout << d << std::endl;
	} 
	catch(const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "-------------------------------------------------------------\n" << std::endl;
	std::cout << "Decrementing and incrementing to overflow grades" << std::endl;
	std::cout << "-------------------------------------------------------------" << std::endl;
	try {
		a.decrementGrade();
		std::cout << a << std::endl;
	} 
	catch(const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	try {
		b.incrementGrade();
		std::cout << b << std::endl;
	} 
	catch(const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "-------------------------------------------------------------\n" << std::endl;
	std::cout << "One overflow from two" << std::endl;
	std::cout << "-------------------------------------------------------------" << std::endl;
	try {
		a.incrementGrade();
		std::cout << a << std::endl;
		b.incrementGrade();
		std::cout << b << std::endl;
	} 
	catch(const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "-------------------------------------------------------------\n" << std::endl;
	std::cout << "Decrementing and incrementing to grades within limits" << std::endl;
	std::cout << "-------------------------------------------------------------" << std::endl;
	try {
		a.incrementGrade();
		std::cout << a << std::endl;
		b.decrementGrade();
		std::cout << b << std::endl;
	} 
	catch(const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	catch(...) {
		std::cout << "-------------------------------------------------------------\n" << std::endl;
	}
	
	return 0;
}
