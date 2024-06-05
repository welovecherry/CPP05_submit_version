#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <stdexcept>

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

};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif