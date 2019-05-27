#include <iostream>
#include <map>
#include <string>
#include <vector>

int main()
{
	std::string line;
	std::vector<std::string> vec;
	while (std::getline(std::cin, line)) vec.push_back(line);
	unsigned two_count = 0, three_count = 0;
	for (const auto &word : vec) {
		std::map<char, int> letter_counts;
		for (const char &ch : word) {
			letter_counts[ch]++;
		}
		bool found_two = false, found_three = false;
		for (const auto &pair : letter_counts) {
			if (pair.second == 2 && !found_two) {
				found_two = true;
				two_count++;
			}
			else if (pair.second == 3 && !found_three) {
				found_three = true;
				three_count++;
			}
		}
	}
	std::cout << two_count * three_count << '\n';
	return 0;
}