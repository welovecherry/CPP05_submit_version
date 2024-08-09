
#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <string>

class ShrubberyCreationForm : public AForm {
private:
    const std::string target;
    static const int signGrade = 145;
    static const int execGrade = 137;

public:
    ShrubberyCreationForm(const std::string &target);
    ShrubberyCreationForm(const ShrubberyCreationForm& other);
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
    virtual ~ShrubberyCreationForm();

    virtual void execute(const Bureaucrat& executor) const;

    std::string getTarget() const;

    // 예외 클래스
    class FileOpenException : public std::exception {
        public:
            virtual const char* what() const throw();
    };
};


#endif