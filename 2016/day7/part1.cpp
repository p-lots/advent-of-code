#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>

bool is_abba(std::string to_test)
{
	return to_test.at(0) != to_test.at(1)
		&& std::equal(to_test.begin(), to_test.begin() + 2, to_test.rbegin());
}

int main(int argc, char *argv[])
{
	std::ifstream file("input.txt");
	std::string line;
	int counter = 0;
	while (std::getline(file, line)) {
		bool abba_within_brackets = false, it_within_brackets = false;
		bool found_abba = false;
		for (unsigned i = 0; i < line.length() - 3; i++) {
			if (line.substr(i, 4).find('[') != std::string::npos) {
				it_within_brackets = true;
			}
			else if (line[i] == ']') {
				it_within_brackets = false;
				continue;
			}
			if (is_abba(line.substr(i, 4))) {
				if (it_within_brackets) {
					abba_within_brackets = true;
					found_abba = false;
					break;
				}
				found_abba = true;
			}
		}
		if (!abba_within_brackets && found_abba) {
			counter++;
		}
	}
	std::cout << counter << '\n';
	return 0;
}