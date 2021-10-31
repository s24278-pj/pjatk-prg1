#include <iostream>
#include <string>

auto print_number (int a) -> void;

auto main (int , char* argv[]) -> int
{
	int counter = std::stoi (argv [1]);
	do {
		print_number (counter);
		counter--;

	} while (counter >= 0);

	return 0;
}

auto print_number (int a) -> void
{
	std::cout  << a << "..." << std::endl;
}

