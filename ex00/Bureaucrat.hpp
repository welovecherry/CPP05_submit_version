#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <stdexcept>

class Bureaucrat
{
	private:
		std::string const name;
		int grade;

	public:
		Bureaucrat(std::string const name, int grade);
	
		std::string getName() const;
		int getGrade();

		void incrementGrade();
		void decrementGrade();

};


#endif