#include <iostream>
#include <set>
#include <sstream>
#include <vector>

std::vector<std::string> tokenize(std::string line)
{
	std::vector<std::string> ret;
	std::stringstream ss(line);
	std::string temp;
	while (std::getline(ss, temp, ' ')) {
		ret.push_back(temp);
	}
	return ret;
}

int main(int argc, char *argv[])
{
	std::string line;
	int total_good = 0;
	while (std::getline(std::cin, line)) {
		auto tokens = tokenize(line);
		std::set<std::string> word_set;
		for (const auto &word : tokens) {
			if (word_set.count(word) == 0) {
				word_set.insert(word);
			}
		}
		if (word_set.size() == tokens.size()) total_good++;
	}
	std::cout << total_good << '\n';
	return 0;
}