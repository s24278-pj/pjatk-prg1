#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

auto main(int argc, char* argv[]) -> int
{
    if (argc == 1) {
        std::cout << "No arguments provided. Exiting..." << std::endl;
        return 1;
    }

    auto expected_options = std::vector<std::string>{"-n", "-r", "-l"};
    auto arguments        = std::vector<std::string>{};
    auto options          = std::vector<std::string>{};

    for (auto i = 1; i < argc; ++i) {
        auto const arg = std::string{argv[i]};
        auto is_option = false;

        for (long unsigned int j = 0; j < expected_options.size(); ++j) {
            if (arg == expected_options[j]) {
                is_option = true;
            }
        }

        if (is_option == false) {
            arguments.push_back(arg);
        } else {
            options.push_back(arg);
        }
    }

    auto n = false;
    auto r = false;
    auto l = false;

    for (long unsigned int i = 0; i < options.size(); ++i) {
        if (options[i].compare("-n") == 0) {
            n = true;
        } else if (options[i].compare("-r") == 0) {
            r = true;
        } else if (options[i].compare("-l") == 0) {
            l = true;
        }
    }

    if (r == true) {
        std::reverse(arguments.begin(), arguments.end());
    }

    for (auto const i = arguments.begin(); i < arguments.end(); ++i) {
        std::cout << *i;
        if (l == true) {
            if ((n == true && i < arguments.end() - 1)
                || (n == false && i < arguments.end())) {
                std::cout << std::endl;
            }
        } else {
            std::cout << " ";
        }
    }

    if (n == false && l == false) {
        std::cout << std::endl;
    }

    return 0;
}
