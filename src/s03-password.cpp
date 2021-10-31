#include <iostream>
#include <string>

auto get_pass (std::string prompt) -> std::string;

auto main (int ,char* argv[]) -> int
{
	std::string pass;
	do {
		pass = get_pass ("password: ");
		std::cout << pass << std::endl;

	} while (pass.compare(argv[1]));
	std::cout << "ok!" <<std::endl;

	return 0;
}

auto get_pass (std::string prompt) -> std::string
{
	std::string a;
	std::cout << prompt;
	std::getline (std::cin, a);
	
	return a;	
}


