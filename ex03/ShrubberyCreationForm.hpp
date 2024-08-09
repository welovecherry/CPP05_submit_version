/*
파일 입출력 구현:
ShrubberyCreationForm에서 파일을 생성하고 ASCII 트리를 작성하는 기능을 구현합니다.
*/

/* 정적상수
클래스의 모든 인스턴스가 공유하는, 변경 불가능한 값.
1. 정적: 클래스의 모든 객체가 공유하는 값. (그래서 메모리 절약 가능)
2. 상수: 값이 변경되지 않는 값
3. 예: static const in GRADE_TO_SIGN = 145;
*/

/* 파일 입출력
1. 헤더: fstream
2. ofstream: 파일 출력 스트림을 이용해 파일을 생성하고 쓸 수 있다.
3. 파일 생성 실패 등의 상황에 대해 예외처리가 필요함
*/

/* 타겟: 파일명을 저장하기 위한 변수
타겟(target)은 ShrubberyCreationForm의 생성자에 전달되는 문자열 매개변수입니다.
이는 생성될 파일의 이름을 결정할 때 사용됨.
예: 타겟이 "home"이면, "home_shrubbery" 파일이 생성됨.
*/

/* execute함수:
구체적인 클래스들의 폼 액션을 실행하는 함수를 구현하세요.
슈루베리에서는 파일을 생성하고 ASCII 트리를 작성하는 것입니다. */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <string> // std::string

class ShrubberyCreationForm : public AForm {
private:
    const std::string target; // variable to store the file name
    static const int signGrade = 145;
    static const int execGrade = 137;

public:
    ShrubberyCreationForm(const std::string &target);
    ShrubberyCreationForm(const ShrubberyCreationForm& other);
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
    virtual ~ShrubberyCreationForm();

    // execute() : AForm의 순수 가상 함수를 오버라이딩
    virtual void execute(const Bureaucrat& executor) const;
/* 버추어가 없다면 기본 클래스의 소멸자만 호출되고, 파생클래스의 소멸자는 호출되지 않는다. 
-> 메모리 누수 생길 수 있다.
*/

    std::string getTarget() const;

/* 정적 상수
클래스의 모든 인스턴스가 공유하는, 변경 불가능한 값.
클래스 내부에서 선언되지만 클래스 외부에서 접근하려면 클래스 이름을 사용해야 한다.

정적 상수는 한번 초기화되면 변경할 수 없다.

반면 전역변수는 어디서든 접근할 수 있고, 어디서든 변경할 수 있다.
*/

    // 파일 열기 실패시 예외 클래스
    class FileOpenException : public std::exception {
        public:
            virtual const char* what() const throw();
    };
};


#endif