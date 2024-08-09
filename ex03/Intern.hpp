#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

/*      typedef AForm* (Intern::*FormCreator)(const std::string& target) const;
1. typedef: 새로운 이름을 지정하는 키워드
2. AForm*: 반환 타입(포인터)
3. (Intern::*FormCreator): 인턴 클래스의 멤버 함수 포인터
4. (const std::string& target): 인자로 받는 문자열
5. const: 함수가 멤버 변수를 변경하지 않음
6. FormCreator: 새로운 이름
*/

/*     static const FormCreator formCreators[numForms];
1. static: 클래스의 모든 객체가 공유하는 값
2. const: 값이 변경되지 않는 값
3. FormCreator: 이전에 정의된 typedef로 인턴 클래스의 특정 멤버 함수를 가리키는 포인터
4. formCreators: 배열의 이름
*/

class Intern {
private:
    typedef AForm* (Intern::*FormCreator)(const std::string& target) const;

    static const int numForms = 3;
    static const std::string formNames[numForms];
    static const FormCreator formCreators[numForms];

    AForm* createShrubberyCreationForm(const std::string& target) const;
    AForm* createRobotomyRequestForm(const std::string& target) const;
    AForm* createPresidentialPardonForm(const std::string& target) const;

public:
    Intern();
    Intern(const Intern& other);
    Intern& operator=(const Intern& other);
    ~Intern();

    AForm* makeForm(const std::string& formName, const std::string& target) const;
};


# endif