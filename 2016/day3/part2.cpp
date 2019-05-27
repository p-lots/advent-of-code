#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

void tokenize(std::string line, std::vector<int> &vec1,
	std::vector<int> &vec2, std::vector<int> &vec3)
{
	std::stringstream ss(line);
	std::string temp;
	ss >> temp;
	vec1.push_back(std::stoi(temp));
	ss >> temp;
	vec2.push_back(std::stoi(temp));
	ss >> temp;
	vec3.push_back(std::stoi(temp));
}

int main(int argc, char *argv[])
{
	int counter = 0;
	std::ifstream file("input.txt");
	std::string line;
	std::vector<int> vec1, vec2, vec3;
	while (std::getline(file, line)) {
		tokenize(line, vec1, vec2, vec3);
		if ((vec1.size() == 3 && vec2.size() == 3) && vec3.size() == 3) {
			std::sort(vec1.begin(), vec1.end());
			std::sort(vec2.begin(), vec2.end());
			std::sort(vec3.begin(), vec3.end());
			if (vec1[0] + vec1[1] > vec1[2]) {
				counter++;
			}
			if (vec2[0] + vec2[1] > vec2[2]) {
				counter++;
			}
			if (vec3[0] + vec3[1] > vec3[2]) {
				counter++;
			}
			vec1.clear();
			vec2.clear();
			vec3.clear();
		}
	}
	std::cout << counter << '\n';
	return 0;
}