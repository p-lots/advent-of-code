#include <fstream>
#include <iostream>
#include <map>
#include <typeinfo>
#include <utility>
#include <vector>

int main(int argc, char *argv[])
{
	std::ifstream file("input.txt");
	std::string line;
	std::vector<std::map<char, int> > map_vec;
	bool first_time = true;
	while (std::getline(file, line)) {
		if (first_time) {
			map_vec = std::vector<std::map<char, int> >(line.length());
			first_time = false;
		}
		for (unsigned i = 0; i < line.length(); i++) {
			map_vec[i][line[i]]++;
		}
	}
	for (auto v_it = map_vec.begin(); v_it != map_vec.end(); v_it++) {
		auto m_it = std::max_element(v_it->begin(), v_it->end(),
			[](std::pair<const char, int> lhs,
				std::pair<const char, int> rhs) {
				// first part is
				// return lhs.second < rhs.second;
				return lhs.second > rhs.second;
		});
		std::cout << m_it->first;
	}
	std::cout << '\n';
	return 0;
}