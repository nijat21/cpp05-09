#include <exception>
#include <iostream>
#include <fstream>
#include <string>
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreationForm", 145, 137), 
	target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : AForm(src), target(src.target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs) {
    if (this != &rhs) {
	    target = rhs.target;
	    AForm::operator=(rhs);
    }
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(const Bureaucrat& b) const {
	checkExecReq(b);
	
	// Create a file <target>_shubbery and write ASCII tree inside that
	std::ofstream out((b.getName() + "_" + target + "_shrubbery").c_str());
	std::ifstream in("tree.txt");
	if(!out || !out.is_open() || !in || !in.is_open())
		throw std::ios_base::failure("File error");

	std::string line;
	while(std::getline(in, line)) 
		out << line << "\n";
}

