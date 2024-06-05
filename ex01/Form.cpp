#include "Form.hpp"
#include "Bureaucrat.hpp"

// Form constructor
Form::Form(const std::string &name, int gradeToSign, int gradeToExecute) : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1) {
		throw std::out_of_range("Grade is too high");
	}
	if (gradeToSign > 150 || gradeToExecute > 150) {
		throw std::out_of_range("Grade is too low");
	}
}

std::string Form::getName() const
{
	return name;
}

bool Form::getIsSigned() const
{
	return isSigned;
}

int Form::getGradeToSign() const
{
	return gradeToSign;
}

int Form::getGradeToExecute() const
{
	return gradeToExecute;
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > gradeToSign) {
		throw std::out_of_range("grade is too low!");
	}
	isSigned = true;
}
std::ostream& operator<<(std::ostream& os, const Form& form) {
	os	<< "📄" << form.getName() << ", form status: " << (form.getIsSigned() ? "✅signed" : "❌not signed")
		<< ", grade required to sign: " << form.getGradeToSign()
		<< ", grade required to execute: " << form.getGradeToExecute();
	return os;
}
