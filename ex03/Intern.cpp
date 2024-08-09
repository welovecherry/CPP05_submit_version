#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

// 정적 멤버 변수 초기화
const std::string Intern::formNames[Intern::numForms] = {
    "shrubbery creation",
    "robotomy request",
    "presidential pardon"
};

// 폼 생성 함수 포인터 배열 초기화
const Intern::FormCreator Intern::formCreators[Intern::numForms] = {
    &Intern::createShrubberyCreationForm,
    &Intern::createRobotomyRequestForm,
    &Intern::createPresidentialPardonForm
};

Intern::Intern() {}

Intern::Intern(const Intern& other) {
    *this = other;
}

Intern& Intern::operator=(const Intern& other) {
    if (this == &other)
        return *this;
    return *this;
}

Intern::~Intern() {}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) const {
    try {
        for (int i = 0; i < numForms; i++) {
            if (formName == formNames[i]) {
                return (this->*formCreators[i])(target);
            }
        }
        throw std::invalid_argument("Form name does not exist"); // cpp 표준 라이브러리에 있는 예외 클래스
    } catch (const std::exception& e) { // 발생할 수 있는 모든 종류의 예외를 포괄하는 범용적인 예외 클래스
        std::cerr << e.what() << std::endl;
        return NULL;
    }
}

// 내부에서 사용할 폼 생성 함수들
AForm* Intern::createShrubberyCreationForm(const std::string& target) const {
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyRequestForm(const std::string& target) const {
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialPardonForm(const std::string& target) const {
    return new PresidentialPardonForm(target);
}