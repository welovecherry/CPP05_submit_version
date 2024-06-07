#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
	{
		Bureaucrat bob("Bob", 4);
		Bureaucrat alice("Alice", 2);
		Form taxForm("Tax Form", 5, 3);
		Form secretForm("Secret Form", 3, 1);

		std::cout << bob << std::endl;
		std::cout << alice << std::endl;

		bob.signForm(taxForm); // success
		alice.signForm(taxForm); // success
		std::cout << std::endl;

		bob.signForm(secretForm); // fail
		alice.signForm(secretForm); // success
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	return 0;
}