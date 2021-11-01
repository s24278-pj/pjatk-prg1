#include <iostream>
#include <cstdlib>
#include <ctime>

auto get_number (int beg, int end) -> int;
auto guess (std::string prompt) -> int;

auto main () -> int
{
	std::srand (std::time(nullptr));
	int right = get_number (1, 100);
	int picked = 0;
	
	do { 
		picked = guess ("guess: ");
		
		if (picked < right)
		{
			std::cout << "number too small! " << std::endl;
		}
		else if (picked > right)
		{
			std::cout << "number too big! " << std::endl;
		}

	 
	} while (picked != right);

	std::cout << "just right! " << std::endl;
	
	return 0;
}

auto get_number (int beg, int end) -> int
{
	return (std::rand () % end) + beg;
}

auto guess (std::string prompt) -> int
{
	std::string g;
	std::cout << prompt;
	std::getline (std::cin, g);
	return std::stoi (g);
}
