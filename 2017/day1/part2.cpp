#include <iostream>
#include <string>
#include <vector>

int main(int argc, char *argv[])
{
	std::string line;
	while (std::getline(std::cin, line)) {
		int sum = 0;
		auto offset = line.length() / 2;
		for (unsigned i = 0; i < line.length(); i++) {
			auto compare_pos = (i + offset) % line.length();
			if (line[i] == line[compare_pos]) {
				sum += line[i] - '0';
			}
		}
		std::cout << sum << '\n';
	}
	return 0;
}