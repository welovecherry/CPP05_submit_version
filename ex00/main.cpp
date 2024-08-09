#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
    try {
        Bureaucrat valid("Valid", 75);
        std::cout << valid << std::endl;

        Bureaucrat tooHigh("TooHigh", 0);
        std::cout << tooHigh << std::endl;
    } catch (const Bureaucrat::GradeTooHighException &e) {
        std::cout << e.what() << std::endl;
    } catch (const Bureaucrat::GradeTooLowException &e) {
        std::cerr << e.what() << std::endl;
    }   
    std::cout << "----------------" << std::endl;
    

    try {
        Bureaucrat tooLow("TooLow", 151);
        std::cout << tooLow << std::endl;
    } catch (const Bureaucrat::GradeTooHighException &e) {
        std::cout << e.what() << std::endl;
    } catch (const Bureaucrat::GradeTooLowException &e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "----------------" << std::endl;

    try {
        Bureaucrat highestRank("HighestRank", 1);
        std::cout << highestRank << std::endl;

        highestRank.incrementGrade();
    } catch (const Bureaucrat::GradeTooHighException &e) {
        std::cout << e.what() << std::endl;
    } catch (const Bureaucrat::GradeTooLowException &e) {
        std::cerr << e.what() << std::endl;
    }    
    std::cout << "----------------" << std::endl;

    try {
        Bureaucrat middleRank("MiddleRank", 75);
        std::cout << middleRank << std::endl;

        middleRank.incrementGrade();
        std::cout << middleRank << std::endl;

        middleRank.decrementGrade();
        std::cout << middleRank << std::endl;
    } catch (const Bureaucrat::GradeTooHighException &e) {
        std::cout << e.what() << std::endl;
    } catch (const Bureaucrat::GradeTooLowException &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}   