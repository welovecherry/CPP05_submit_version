#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib> // rand()
#include <ctime> // time()

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) 
    : AForm("RobotomyRequestForm", signGrade, execGrade), target(target) {
    std::srand(std::time(0)); // 현재시간을 이용해 초기화
}

// 복사생성자는 객체의 모든 멤버를 다른객체의 멤버로 복사해야한다.
// 상속받은 클래스의 멤버 변수는 초기화 목록에서 초기화해야한다. 따라서 AForm(other)로 초기화해야한다.
// AForm(other)로 초기화하면 AForm의 복사생성자가 호출되어 AForm의 멤버 변수를 복사한다.
// target은 자신의 멤버 변수이므로 초기화 목록에서 직접 초기화해야한다.
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) 
    : AForm(other), target(other.target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    if (this == &other)
        return *this;
    AForm::operator=(other); // 베이스 클래스의 대입연산자 호출해서 베이스 클래스 멤버 변수 복사
    target = other.target; // RobotomyRequestForm의 멤버 변수인 target을 other 객체의 타깃으로 복사
    return *this; // 연속 대입을 지원하기 위해 자기 자신을 반환
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
    if (!this->getIsSigned())
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > this->getGradeToExecute())
        throw AForm::GradeTooLowException();

    // 0 ~ 99 사이의 난수 생성
    int randomNum = std::rand() % 100;
    std::cout << "Drill noise!!!!! DDDDDDDDDDDDD" << std::endl;

    if (randomNum < 50)
        std::cout << target << " has been robotomized successfully ✅" << std::endl;
    else
        std::cout << target << " robotomization failed ❌" << std::endl;

}

std::string RobotomyRequestForm::getTarget() const {
    return target;
}