#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

std::vector<int> tokenize(std::string line)
{
	std::stringstream ss(line);
	std::string temp;
	std::vector<int> ret;
	while (ss >> temp) {
		ret.push_back(std::stoi(temp));
	}
	return ret;
}

int main(int argc, char *argv[])
{
	int counter = 0;
	std::ifstream file("input.txt");
	std::string line;
	while (std::getline(file, line)) {
		auto tokens = tokenize(line);
		// auto tokens = tokenize("");

		std::sort(tokens.begin(), tokens.end());
		if (tokens[0] + tokens[1] > tokens[2]) {
			counter++;
		}
	}
	std::cout << counter << '\n';
	return 0;
}