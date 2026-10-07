#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {

    std::cout << "Creating bureaucrats with proper grades" << std::endl;
    std::cout << "-------------------------------------------------------------" << std::endl;
    try {
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
        std::cout << tax << std::endl;
        std::cout << "-------------------------------------------------------------\n" << std::endl;
        std::cout << "Sign the form" << std::endl;
        std::cout << "-------------------------------------------------------------" << std::endl;
        b.signForm(tax);
        std::cout << tax << std::endl;
        std::cout << "-------------------------------------------------------------\n" << std::endl;
        std::cout << "Form be signed" << std::endl;
        std::cout << "-------------------------------------------------------------" << std::endl;
        tax.beSigned(b);
        std::cout << tax << std::endl;
        std::cout << "-------------------------------------------------------------\n" << std::endl;
        std::cout << "Form be signed" << std::endl;
        std::cout << "-------------------------------------------------------------" << std::endl;
        tax.beSigned(a);
        std::cout << tax << std::endl;
        std::cout << "-------------------------------------------------------------\n" << std::endl;
        std::cout << "Form be signed" << std::endl;
        std::cout << "-------------------------------------------------------------" << std::endl;
        tax.beSigned(b);
        std::cout << tax << std::endl;
        std::cout << "-------------------------------------------------------------\n" << std::endl;
    } catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
    }

    return 0;
}
