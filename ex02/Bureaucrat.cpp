#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(const std::string &name, int grade) : name(name) {
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

int Bureaucrat::getGrade() const {
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

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat) {
  os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
  return os;
}

void Bureaucrat::signForm(Form &form) const {
  try {
    form.beSigned(*this);
    std::cout << "✅" << name << " signs " << form.getName() << std::endl;
  } catch (std::exception &e) {
    std::cout << "❌" << name << " cannot sign " << form.getName() << " because " << e.what() << std::endl;
  }
}