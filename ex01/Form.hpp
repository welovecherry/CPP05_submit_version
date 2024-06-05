#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include <stdexcept>

class Bureaucrat;

class Form
{
	private:
		const std::string name; // 양식의 이름
		bool isSigned; // 서명 여부
		const int gradeToSign; // 서명을 위한 최소 등급
		const int gradeToExecute; // 실행을 위한 최소 등급

	public:
		Form(const std::string &name, int gradeToSign, int gradeToExecute);

		std::string getName() const;
		bool getIsSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		void beSigned(const Bureaucrat &bureaucrat);
};

std::ostream &operator<<(std::ostream &os, const Form &form);


#endif