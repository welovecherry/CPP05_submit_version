#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
	{
		Bureaucrat bob("Bob", 51);
		Form taxForm("Tax Form", 50, 100);

		// print bob and taxForm
		std::cout << bob << std::endl;
		std::cout << taxForm << std::endl;
		std::cout << std::endl;
		
		// bob signs taxForm and fails
		bob.signForm(taxForm);
		std::cout << taxForm << std::endl;
		std::cout << std::endl;

		// increment bob's grade and sign taxForm
		bob.incrementGrade();
		bob.signForm(taxForm);
		std::cout << taxForm << std::endl;
		std::cout << std::endl;

		// TODO:  높은 등급의 Bureaucrat 생성 및 서명 시도 (성공할 것)


	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}