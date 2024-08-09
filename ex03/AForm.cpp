#include "AForm.hpp"
#include "Bureaucrat.hpp"

// constructor
AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute)
    : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

// copy constructor 
AForm::AForm(const AForm& other)
    : name(other.name), isSigned(other.isSigned), 
    gradeToSign(other.gradeToSign), 
    gradeToExecute(other.gradeToExecute) {}

// assignment operator
AForm& AForm::operator=(const AForm& other) {
    if (this == &other)
        return *this;
    isSigned = other.isSigned;
    return *this;
}

// destructor
AForm::~AForm() {}


// exception classes
const char* AForm::GradeTooHighException::what() const throw() {
    return "Grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Grade is too low";
}

// 추가된 클래스
const char* AForm::FormNotSignedException::what() const throw() {
    return "Form is not signed";
}

// getter methods
const std::string &AForm::getName() const {
    return name;
}

bool AForm::getIsSigned() const {
    return isSigned;
}

int AForm::getGradeToSign() const {
    return gradeToSign;
}

int AForm::getGradeToExecute() const {
    return gradeToExecute;
}

// beSigned() member function
void AForm::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() <= gradeToSign)
        isSigned = true;
    else
        throw AForm::GradeTooLowException();
}

// << operator overloading
std::ostream& operator<<(std::ostream& os, const AForm& aform) {
    os << "Form name: " << aform.getName() << std::endl;
    os << "Is signed: " << aform.getIsSigned() << std::endl;
    os << "Grade to sign: " << aform.getGradeToSign() << std::endl;
    os << "Grade to execute: " << aform.getGradeToExecute() << std::endl;
    return os;
}
