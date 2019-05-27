#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

typedef struct {
	char letter;
	int count;
} Count_Pair;

void parse_line(std::string line, /*std::vector<std::string> &tokens,*/
	std::vector<std::string> &rotated_words)
{
	std::string::size_type start = 0, end;
	char delim = '-';
	std::vector<std::string> tokens;
	while ((end = line.find(delim, start)) != std::string::npos) {
		tokens.push_back(line.substr(start, end - start));
		start = end + 1;
	}
	//tokens.push_back(line.substr(start));
	auto checksum_and_sector_id = line.substr(start);

	//auto checksum_and_sector_id = tokens.back();
	auto end_of_number = checksum_and_sector_id.find('[');
	int rotation = std::stoi(checksum_and_sector_id.substr(0, end_of_number));
	//std::cout << "rotation: " << rotation << '\n';

	// std::vector<std::string> rotated_words;

	for (std::string str : tokens) {
		//std::cout << "str in tokens: " << str << '\n';
		std::string new_str;
		for (char c : str) {
			char new_c =
				static_cast<char>(((static_cast<int>(c) - 'a')
					+ (rotation % 26)) % 26 + 'a');
			new_str.push_back(new_c);
		}
		//std::cout << "new_str: " << new_str << '\n';
		rotated_words.push_back(new_str);
	}
}

int main(int argc, char *argv[])
{
	std::ifstream file("input.txt");
	std::string line;
	int sum = 0;
	
	while (std::getline(file, line)) {
		//std::vector<std::string> tokens;
		std::vector<std::string> rotated_words;
		parse_line(line, rotated_words);
		/*
		for (std::string token : tokens) {
			std::cout << '<' << token << ">\n";
		} */
		//std::cout << std::string (15, '=') << '\n';
		//tokens.clear();
		//*/
		for (auto it = rotated_words.begin(); it != rotated_words.end(); it++) {
			std::cout << *it;
			if (it != rotated_words.end() - 1) {
				std::cout << ' ';
			}
			else {
				std::cout << '\n';
			}
		}
		
	}
	std::cout << std::string (15, '=') << '\n';
	return 0;
}