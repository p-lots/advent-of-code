#include <fstream>
#include <iostream>
#include <map>
#include <utility>
#include <vector>

int main(int argc, char *argv[])
{
	std::ifstream file("test.txt");
	std::string line;
	std::map<std::pair<char, unsigned>, int> letter_counts;
	bool first_time = true;
	unsigned length;
	while (std::getline(file, line)) {
		for (unsigned i = 0; i < line.length(); i++) {
			letter_counts[std::make_pair(line[i], i)]++;
		}
		if (first_time) {
			length = line.length();
		}
	}
	std::vector<std::pair<std::pair<char, unsigned>, unsigned> > vec_letter_counts;
	for (auto p : letter_counts) {
		vec_letter_counts.push_back(std::make_pair(
			std::make_pair(p.first.first, p.first.second), p.second));
	}
	std::sort(vec_letter_counts.begin(), vec_letter_counts.end(),
		[](std::pair<std::pair<char, unsigned>, int> lhs,
			std::pair<std::pair<char, unsigned>, int> rhs) {
			//return /*(lhs.first.second < rhs.first.second) &&*/ (lhs.second > rhs.second)
			//if (lhs.second > rhs.second) {
			if (lhs.first.second < rhs.first.second) {
				//return lhs.first.second < rhs.first.second;
				return lhs.second > rhs.second;
			}
			else if (lhs.second < rhs.second) {
				//return lhs.second > rhs.second;
				return lhs.first.second < rhs.first.second;
			}
			return lhs.second > rhs.second;
			//return lhs.first.second < rhs.first.second;

			/*
			if (lhs.first.second == rhs.first.second) {
				return lhs.second > rhs.second;
			}
			else if (lhs.first.second < rhs.first.second) {
				return lhs.second > rhs.second;
			}
			//return lhs.first.first < rhs.first.first;
			return lhs.second > rhs.second;
			*/
	});

	std::string result;

	for (auto it = vec_letter_counts.begin();
		it != vec_letter_counts.begin() + length; it++) {
		result += it->first.first;
	}

	std::cout << result << '\n';
	return 0;
}
/*
(
		[](std::map<std::pair<char, unsigned>, int>::iterator lhs,
			std::map<std::pair<char, unsigned>, int>::iterator rhs) {
			if (lhs->first.second == rhs->first.second) {
				return lhs->second > rhs->second;
			}
			else if (lhs->first.second < rhs->first.second) {
				return lhs->second > rhs->second;
			}
			return lhs.first.first < rhs.first.first;
		});
*/