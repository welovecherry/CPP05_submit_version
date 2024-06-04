#include "Bureaucrat.hpp"

int main()
{
	// 특정 예외 처리:
	try {
		Bureaucrat b("John", 2);
		std::cout << b << std::endl;

		b.incrementGrade();
		std::cout << b << std::endl;

		b.incrementGrade();
		std::cout << b << std::endl;

	} catch (const std::out_of_range &e) {
		std::cerr << "Out of range: " << e.what() << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	// 일반 예외 처리


	return 0;
}