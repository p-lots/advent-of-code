#include <iostream>
#include <set>
#include <vector>

int main()
{
	std::string line;
	std::vector<int> v;
	while (std::getline(std::cin, line)) {
		if (line[0] == '+') v.push_back(std::stoi(line.substr(1)));
		else v.push_back(std::stoi(line));
	}
	unsigned i = 0;
	std::set<int> already_seen;
	unsigned long long int freq = 0;
	while (true) {
		freq += v[i];
		if (already_seen.count(freq) == 0) already_seen.insert(freq);
		else break;
		i++;
		if (!(i < v.size())) i = 0;
	}
	std::cout << freq << '\n';
	return 0;
}