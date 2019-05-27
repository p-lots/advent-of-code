#include <iostream>
#include <cmath>
#include <string>
#include <vector>

int main(int argc, char *argv[])
{
	std::string line;
	std::vector<int> input;
	while (std::getline(std::cin, line)) {
		input.push_back(std::stoi(line));
	}
	std::cout << input.size() << '\n';
	int curr = 0, num_steps = 0;
	while (true) {
		int steps_to_move = input[curr];
		if (curr + steps_to_move > input.size()) break;
		input[curr]++;
		curr += steps_to_move;
		num_steps++;
	}
	std::cout << num_steps << '\n';
	return 0;
}