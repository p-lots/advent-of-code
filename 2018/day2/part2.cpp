#include <iostream>
#include <set>
#include <string>
#include <vector>

int main()
{
	std::string line;
	std::vector<std::string> vec;
	while (std::getline(std::cin, line)) vec.push_back(line);
	bool break_all = false;
	for (unsigned i = 0; i < vec[0].size(); i++) {
		std::set<std::string> table;
		for (unsigned j = 0; j < vec.size(); j++) {
			std::string new_item = vec[j].substr(0, i) + vec[j].substr(i + 1);
			auto result = table.insert(new_item);
			if (!result.second) {
				std::cout << new_item << '\n';
				break_all = true;
				break;
			}
		}
		if (break_all) break;
	}
	return 0;
}

/*

int diff_finder(const std::string &first, const std::string &second)
{
	if (first.length() != second.length()) return -1;
	int ret = 0;
	for (unsigned i = 0; i < first.length(); i++) {
		if (first[i] != second[i]) ret++;
	}
	return ret;
}

int main()
{
	std::string line;
	std::vector<std::string> vec;
	while (std::getline(std::cin, line)) vec.push_back(line);
	bool break_all = false;
	for (unsigned i = 0; i < vec.size(); i++) {
		for (unsigned j = i + 1; j < vec.size() - 1; j++) {
			int val = diff_finder(vec[i], vec[j]);
			if (val == 1) {
				std::cout << vec[i] << "\n" << vec[j] << "\n";
				break_all = true;
				break;
			}
		}
		if (break_all) break;
	}
	return 0;
}

*/