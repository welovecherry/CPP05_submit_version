#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string const name, int grade) : name(name) {
  if (grade < 1) {
    throw std::out_of_range("Grade is too high");
  } else if (grade > 150) {
    throw std::out_of_range("Grade is too low");
  }
  this->grade = grade;
}

std::string Bureaucrat::getName() const {
  return this->name;
}

int Bureaucrat::getGrade() {
  return this->grade;
}

void Bureaucrat::incrementGrade() {
  if (this->grade == 1) {
    throw std::out_of_range("Grade is too high!");
  }
  this->grade--;
}

void Bureaucrat::decrementGrade() {
  if (this->grade == 150) {
    throw std::out_of_range("Grade is too low!");
  }
  this->grade++;
}
