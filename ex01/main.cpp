#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
    try {
        Bureaucrat highRank("High rank", 1);
        Bureaucrat lowRank("Low rank", 150);

        Form form("Important form", 1, 50);
        std::cout << form << std::endl;

        highRank.signForm(form);
        lowRank.signForm(form);

        highRank.decrementGrade();
        highRank.signForm(form);

    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}   