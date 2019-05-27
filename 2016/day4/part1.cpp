#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

typedef struct {
	char letter;
	int count;
} Count_Pair;

void parse_line(std::string line, std::vector<std::string> &tokens,
	std::map<char, int> &char_counts, std::vector<Count_Pair> &v,
	int &num_on_checksum, bool &is_valid_room)
{
	std::string::size_type start = 0, end;
	char delim = '-';
	//std::vector<std::string> tokens;
	while ((end = line.find(delim, start)) != std::string::npos) {
		tokens.push_back(line.substr(start, end - start));
		start = end + 1;
	}
	tokens.push_back(line.substr(start));
	//
	std::vector<std::string> chars_to_count(tokens.begin(), tokens.end() - 1);
	///*
	std::string checksum = tokens.back();
	for (std::string str : chars_to_count) {
		for (char c : str) {
			char_counts[c]++;
		}
	}
	//
	
	///*
	for (auto &p : char_counts) {
	//	std::cout << p.first << " => " << p.second << '\n';
		Count_Pair c_p = { p.first, p.second };
		v.push_back(c_p);
	}
	std::sort(v.begin(), v.end(), [](Count_Pair lhs, Count_Pair rhs) {
		if (lhs.count == rhs.count) {
			return static_cast<int>(lhs.letter)
				< static_cast<int>(rhs.letter);
		}
		else {
			return lhs.count > rhs.count; 
		} });//*/
	std::string checksum_expected = "";
	for (int i = 0; i < 5; i++) {
		checksum_expected += v.at(i).letter;
	}
	auto checksum_start = checksum.find('[') + 1;
	auto checksum_end = checksum_start + 5;
	num_on_checksum = std::stoi(checksum.substr(0, checksum_start));
	std::string checksum_actual = checksum.substr(checksum_start,
		checksum_end - checksum_start);
	if (checksum_expected == checksum_actual) {
		is_valid_room = true;
	}
	//
}

int main(int argc, char *argv[])
{
	std::ifstream file("input.txt");
	std::string line;
	int sum = 0;
	
	
	while (std::getline(file, line)) {
		std::vector<std::string> tokens;
		std::map<char, int> char_counts;
		std::vector<Count_Pair> v;
		int num_on_checksum;
		bool is_valid_room = false;
		parse_line(line, tokens, char_counts, v, num_on_checksum, is_valid_room);
		/*
		for (std::string token : tokens) {
			std::cout << '<' << token << ">\n";
		} */
		//std::cout << std::string (15, '=') << '\n';
		//tokens.clear();
		//*/
		if (is_valid_room) {
			sum += num_on_checksum;
		}
	}
	std::cout << sum << '\n';
	return 0;
}