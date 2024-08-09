/*
add the executeForm(AForm const & form) member function to the Bureau- crat.
*/

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream> 
# include <string> 
# include <exception>

class AForm;

class Bureaucrat {
private:
    const std::string name;
    int grade;

public:
    Bureaucrat();
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat& operator=(const Bureaucrat& other);
    ~Bureaucrat();

    Bureaucrat(const std::string &name, int grade);
    
    const std::string &getName() const;
    int getGrade() const;

    void incrementGrade();
    void decrementGrade();

    class GradeTooHighException : public std::exception {
    public:
        const char* what() const throw();
    };
    // GradeTooHighException에서 virtual 써야할까? 
    // 쓰지 않아도 된다. 왜냐하면 GradeTooHighException은 다른 클래스에서 상속받지 않기 때문이다.

    class GradeTooLowException : public std::exception {    
    public:
        const char* what() const throw();
    };

    // signForm() member function
    void signForm(class AForm& aform);
};  

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif