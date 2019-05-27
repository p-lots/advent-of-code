#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
	std::string line;
	while (std::getline(std::cin, line)) {
		int f = 0;
		for (const char &c : line) {
			if (c == '(') {
				f++;
			}
			else if (c == ')') {
				f--;
			}
		}
		std::cout << f << '\n';
	}
	return 0;
}