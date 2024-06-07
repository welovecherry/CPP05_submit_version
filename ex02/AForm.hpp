#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>
#include <stdexcept>

/*
TODO: 기본 클래스 AForm의 추상 클래스화:

"In all cases, the base class Form must be an abstract class, and therefore should be renamed AForm."
추상 클래스는 최소한 하나의 순수 가상 함수를 포함해야 합니다. 이는 다형성을 구현하기 위한 첫 번째 단계입니다.

"Add the following concrete classes: ShrubberyCreationForm, RobotomyRequestForm, PresidentialPardonForm"

Now, add the execute(Bureaucrat const & executor) const member function to the base form and implement a function to execute the form’s action of the concrete classes. You have to check that the form is signed and that the grade of the bureaucrat attempting to execute the form is high enough. Otherwise, throw an appropriate exception.
*/


class Bureaucrat;

class AForm
{
	private:
		const std::string name; // 양식의 이름
		bool isSigned; // 서명 여부
		const int gradeToSign; // 서명을 위한 최소 등급
		const int gradeToExecute; // 실행을 위한 최소 등급

	public:
		AForm(const std::string &name, int gradeToSign, int gradeToExecute);
		/*가상 소멸자는 다형성(polymorphism)을 사용하는 클래스 계층에서 중요한 역할을 합니다. `AForm` 클래스의 소멸자를 가상으로 선언하는 이유는 다음과 같습니다:

		- **다형성 지원**: `AForm`은 추상 클래스이며, 이를 상속받는 파생 클래스들이 존재합니다. 만약 `AForm`의 포인터로 파생 클래스 객체를 가리키는 경우, 해당 객체를 삭제할 때 파생 클래스의 소멸자가 호출되지 않을 수 있습니다. 이는 자원을 제대로 해제하지 못해 메모리 누수가 발생할 수 있습니다.
		- **정확한 소멸자 호출**: 가상 소멸자를 사용하면, `delete` 연산자를 통해 기본 클래스 포인터로 파생 클래스 객체를 삭제할 때, 정확한 파생 클래스의 소멸자가 호출됩니다. 이를 통해 자원이 올바르게 해제됩니다.*/
		virtual ~AForm();

		std::string getName() const;
		bool getIsSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		void beSigned(const Bureaucrat &bureaucrat);
		
		// create execute function
		/* based on the requirement to implement the execute function in the derived classes, it would be appropriate to make the execute function virtual in the base class AForm. This allows for dynamic dispatch and enables polymorphic behavior when calling the execute function on objects of derived classes. */
		virtual void execute(Bureaucrat const &executor) const = 0;
};

std::ostream &operator<<(std::ostream &os, const AForm &form);


#endif