#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream> 
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("ShrubberyCreationForm", signGrade, execGrade), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other), target(other.target) {} 

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    if (this == &other)
        return *this;
    AForm::operator=(other);
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

// 추가한 예외처리
const char *ShrubberyCreationForm::FileOpenException::what() const throw() {
    return "Error: file open failed";
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
    this->checkExecution(executor);
    
    std::string filename = target + "_shrubbery";
    std::ofstream file(filename.c_str());
    if (!file.is_open())
    {
        throw FileOpenException();
    }

    file << "    *    " << std::endl;
    file << "   ***   " << std::endl;
    file << "  *****  " << std::endl;
    file << " ******* " << std::endl;
    file << "*********" << std::endl;
    file << "    |    " << std::endl;
    file << "    |    " << std::endl;

    file.close();
}

std::string ShrubberyCreationForm::getTarget() const {
    return target;
}