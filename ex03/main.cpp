#include "Bureaucrat.hpp"
#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() {
    try {
        Bureaucrat bob4("Bob4", 1);
        std::cout << bob4 << std::endl;

        Intern intern;
        std::string formNames[] = {"shrubbery creation", "robotomy request", "presidential pardon", "unknown form"};
        std::string targets[] = {"Home", "Robot", "Alice", "Unknown"};

        for (int i = 0; i < 4; i++) {
            AForm *form = intern.makeForm(formNames[i], targets[i]);
            if (form) {
                form->beSigned(bob4);
                std::cout << *form << std::endl;

                form->execute(bob4);
                delete form;
            }
        }
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}