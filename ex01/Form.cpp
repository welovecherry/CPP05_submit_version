#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

// constructor
Form::Form(const std::string &name, int gradeToSign, int gradeToExecute)
    : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw Form::GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw Form::GradeTooLowException();
}

// copy constructor
Form::Form(const Form& other)
    : name(other.name), isSigned(other.isSigned), 
    gradeToSign(other.gradeToSign), 
    gradeToExecute(other.gradeToExecute) {}

// assignment operator
Form& Form::operator=(const Form& other) {
    if (this == &other)
        return *this;
    isSigned = other.isSigned;
    return *this;
}

// destructor
Form::~Form() {}

// exception classes
const char* Form::GradeTooHighException::what() const throw() {
    return "Grade is too high";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Grade is too low";
}

// getter methods
const std::string &Form::getName() const {
    return name;
}

bool Form::getIsSigned() const {
    return isSigned;
}

int Form::getGradeToSign() const {
    return gradeToSign;
}

int Form::getGradeToExecute() const {
    return gradeToExecute;
}

// beSigned() :공무원 등급이 충분히 높으면 Form 객체의 상태를 '서명된' 상태로 변경한다.
void Form::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() <= gradeToSign)
        isSigned = true;
    else
        throw Form::GradeTooLowException();
}

// << operator overloading
std::ostream& operator<<(std::ostream& os, const Form& form) {
    os << "Form name: " << form.getName() << std::endl;
    os << "Is signed: " << form.getIsSigned() << std::endl;
    os << "Grade to sign: " << form.getGradeToSign() << std::endl;
    os << "Grade to execute: " << form.getGradeToExecute() << std::endl;
    return os;
}