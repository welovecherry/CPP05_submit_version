#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <stdexcept>

/*
executeForm(AForm const & form) 멤버 함수를 추가하세요. 이 함수는 양식 실행을 시도해야 합니다. 성공하면 다음과 같은 메시지를 출력하세요:

<bureaucrat> executed <form>

성공하지 못하면 명확한 오류 메시지를 출력하세요.
*/

class Form;

class Bureaucrat
{
	private:
		const std::string name;
		int grade;

	public:
		Bureaucrat(const std::string &name, int grade);
	
		std::string getName() const;
		int getGrade() const;

		void incrementGrade();
		void decrementGrade();
		void signForm(Form &form) const;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif