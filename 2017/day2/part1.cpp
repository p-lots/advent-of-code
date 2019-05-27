#include <iostream>
#include <climits>
#include <sstream>

int main(int argc, char *argv[])
{
	std::string line;
	int sum = 0;
	while (std::getline(std::cin, line)) {
		std::stringstream ss(line);
		int temp, max = INT_MIN, min = INT_MAX;
		while (ss >> temp) {
			if (temp > max) {
				max = temp;
			}
			if (temp < min) {
				min = temp;
			}
		}
		sum += max - min;
	}
	std::cout << sum << '\n';
	return 0;
}