#include <iostream>
#include <sstream>
#include <vector>

int main(int argc, char *argv[])
{
	std::string line;
	int sum = 0;
	while (std::getline(std::cin, line)) {
		std::stringstream ss(line);
		int temp;
		std::vector<int> nums;
		while (ss >> temp) {
			nums.push_back(temp);
		}
		bool break_all = false;
		for (unsigned i = 0; i < nums.size(); i++) {
			for (unsigned j = 0; j < nums.size(); j++) {
				if (nums[i] % nums[j] == 0 && nums[i] != nums[j]) {
					sum += nums[i] / nums[j];
					break_all = true;
					break;
				}
			}
			if (break_all) break;
		}
	}
	std::cout << sum << '\n';
	return 0;
}