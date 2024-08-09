#include "Bureaucrat.hpp"
#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

void leaks() {
    system("leaks ex03");
}

int main() {
    atexit(leaks);

    try {
        Bureaucrat bob("Bob", 1);
        Bureaucrat alice("Alice", 150);

        std::cout << bob << std::endl;
        std::cout << alice << std::endl;

        ShrubberyCreationForm form("home");
        std::cout << "Form created for target: " << form.getTarget() << std::endl;
        { 
        // form.beSigned(bob);
        // std::cout << "Form signed by " << bob.getName() << std::endl;

        // form.execute(bob);
        // std::cout << "Form executed by " << bob.getName() << std::endl;
        }
        form.execute(alice);
        std::cout << "Form executed by " << alice.getName() << std::endl;

    } catch (const AForm::FormNotSignedException& e) {
        std::cerr << e.what() << std::endl;
    } catch (const AForm::GradeTooLowException& e) {
        std::cerr << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "======================================" << std::endl;

    try {
        Bureaucrat bob2("Bob2", 1);
        Bureaucrat alice2("Alice2", 150);

        std::cout << bob2 << std::endl;
        std::cout << alice2 << std::endl;

        RobotomyRequestForm form2("Target");
        std::cout << "Form created for target: " << form2.getTarget() << std::endl;
        form2.beSigned(bob2);
        form2.execute(bob2);

        form2.execute(alice2);
    }
    catch (const AForm::FormNotSignedException& e) {
        std::cerr << e.what() << std::endl;
    }
    catch (const AForm::GradeTooLowException& e) {
        std::cerr << e.what() << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "======================================" << std::endl;

    try {
        Bureaucrat bob3("Bob3", 1);
        Bureaucrat alice3("Alice3", 150);
        std::cout << bob3 << std::endl;
        std::cout << alice3 << std::endl;

        PresidentialPardonForm form3("Target");
        std::cout << "Form created for target: " << form3.getTarget() << std::endl;

        form3.beSigned(bob3);
        form3.execute(bob3);
        form3.execute(alice3);
        
    }
    catch (const AForm::FormNotSignedException& e) {
        std::cerr << e.what() << std::endl;
    }
    catch (const AForm::GradeTooLowException& e) {
        std::cerr << e.what() << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "======================================" << std::endl;

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
                form->execute(bob4);
                delete form;
            }
        }
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}