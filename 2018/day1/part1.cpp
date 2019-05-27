#include <iostream>
#include <numeric>
#include <vector>

int main()
{
	std::string line;
	std::vector<int> v;
	while (std::getline(std::cin, line)) {
		if (line[0] == '+') {
			v.push_back(std::stoi(line.substr(1)));
		}
		else {
			v.push_back(std::stoi(line));
		}
	}
	std::cout << std::accumulate(v.begin(), v.end(), 0) << '\n';
	return 0;
}