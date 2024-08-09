#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib> // rand()
#include <ctime> // time()

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) 
    : AForm("RobotomyRequestForm", signGrade, execGrade), target(target) {
    std::srand(std::time(0));
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) 
    : AForm(other), target(other.target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    if (this == &other)
        return *this;
    AForm::operator=(other);
    target = other.target;
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
    this->checkExecution(executor);

    int randomNum = std::rand() % 100;
    std::cout << "Drill noise!!!!! DDDDDDDDDDDDD" << std::endl;

    if (randomNum < 50)
        std::cout << target << " has been robotomized successfully ✅" << std::endl;
    else
        std::cout << target << " robotomization failed ❌" << std::endl;
}

std::string RobotomyRequestForm::getTarget() const {
    return target;
}