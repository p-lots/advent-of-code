#include <iostream>
#include <map>
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

std::map<char, int> make_map(std::string word)
{
	std::map<char, int> ret;
	for (const auto &c : word) {
		ret[c]++;
	}
	return ret;
}

int main(int argc, char *argv[])
{
	std::string line;
	int total_good = 0;
	while (std::getline(std::cin, line)) {
		auto tokens = tokenize(line);
		std::set<std::map<char, int> > word_map_set;
		bool is_valid = true;
		for (const auto &word : tokens) {
			auto phrase_map = make_map(word);
			if (word_map_set.count(phrase_map) == 0) {
				word_map_set.insert(phrase_map);
			}
			else if (word_map_set.count(phrase_map) == 1) {
				is_valid = false;
			}
		}
		if (is_valid) total_good++;
	}
	std::cout << total_good << '\n';
	return 0;
}