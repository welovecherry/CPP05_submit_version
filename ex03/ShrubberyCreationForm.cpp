#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream> // std::ofstream
#include <iostream>

/*왜 AForm을 사용하는가?
ShrubberyCreationForm 클래스는 AForm 클래스를 상속받습니다. 
따라서 ShrubberyCreationForm 객체가 생성될 때, AForm 클래스의 생성자가 먼저 호출되어야 합니다. 
이것이 바로 클래스 상속에서의 객체 초기화 순서입니다. 
기본 클래스의 생성자가 호출되지 않으면, 기본 클래스의 멤버 변수들이 초기화되지 않습니다.*/

// orthodox canonical form
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("ShrubberyCreationForm", signGrade, execGrade), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other), target(other.target) {} 

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    if (this == &other)
        return *this;
    AForm::operator=(other); // AForm의 대입연산자 호출(기본 클래스의 대입연산자 호출)
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

// 파일 생성 실패 예외처리
const char *ShrubberyCreationForm::FileOpenException::what() const throw() {
    return "Error: file open failed";
}

// execute() : AForm의 순수 가상 함수를 오버라이딩
void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
    if (!this->getIsSigned())
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > this->getGradeToExecute())
        throw AForm::GradeTooLowException();
    
    std::string filename = target + "_shrubbery";
    std::ofstream file(filename.c_str()); // 98version
    if (!file.is_open())
    {
        throw FileOpenException();
    }

    // draw ASCII tree
    file << "    *    " << std::endl;
    file << "   ***   " << std::endl;
    file << "  *****  " << std::endl;
    file << " ******* " << std::endl;
    file << "*********" << std::endl;
    file << "    |    " << std::endl;
    file << "    |    " << std::endl;

    file.close();
}



// getter
std::string ShrubberyCreationForm::getTarget() const {
    return target;
}