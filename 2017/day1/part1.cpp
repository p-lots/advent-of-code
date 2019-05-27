#include <iostream>
#include <string>
#include <vector>

int main(int argc, char *argv[])
{
	std::string line;
	int sum = 0;
	while (std::getline(std::cin, line)) {
		for (unsigned i = 0; i < line.length() - 1; i++) {
			if (line[i] == line[i + 1]) {
				sum += line[i] - '0';
			}
		}
	}
	if (line[0] == line[line.length() - 1]) {
		sum += line[0] - '0';
	}
	std::cout << sum << '\n';
	return 0;
}