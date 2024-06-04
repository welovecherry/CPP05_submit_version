#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include <stdexcept>
//#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string name;
		bool isSigned;
		const int gradeToSign;
		const int gradeToExecute;

	public:
		Form(const std::string &name, int gradeToSign, int gradeToExecute);

		std::string getName() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;

		void incrementGradeToSign();
		void decrementGradeToSign();
		void incrementGradeToExecute();
		void decrementGradeToExecute();

		void beSigned(const Bureaucrat &bureaucrat);
};

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif