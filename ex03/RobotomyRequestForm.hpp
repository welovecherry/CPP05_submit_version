#ifndef RobotomyRequestForm_HPP
# define RobotomyRequestForm_HPP

#include "AForm.hpp"
#include <string>
#include <iostream>

class RobotomyRequestForm : public AForm {
private:
    std::string target;
    static const int signGrade = 72;
    static const int execGrade = 45;

public:
    RobotomyRequestForm(const std::string &target);
    RobotomyRequestForm(const RobotomyRequestForm& other);
    RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
    virtual ~RobotomyRequestForm();

    void execute(const Bureaucrat& executor) const;
    std::string getTarget() const;
};

#endif