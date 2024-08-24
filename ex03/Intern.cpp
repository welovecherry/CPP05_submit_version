#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

const std::string Intern::formNames[Intern::numForms] = {
    "shrubbery creation",
    "robotomy request",
    "presidential pardon"
};


// 폼 생성 함수 포인터 배열 초기화
// formCreators: 함수포인터의 배열
// 각 원소는 특정 종류의 양식을 생성하는 함수를 가리킵니다.
const Intern::FormCreator Intern::formCreators[Intern::numForms] = {
    &Intern::createShrubberyCreationForm, // Shrubbery Creation 양식을 만드는 함수의 주소
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
        throw std::invalid_argument("Form name does not exist");
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return NULL;
    }
}

AForm* Intern::createShrubberyCreationForm(const std::string& target) const {
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyRequestForm(const std::string& target) const {
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialPardonForm(const std::string& target) const {
    return new PresidentialPardonForm(target);
}
