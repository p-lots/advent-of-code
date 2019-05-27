#include <iostream>
#include <vector>

int main(int argc, char *argv[])
{
	std::string line;
	std::getline(std::cin, line);
	int x_count = 1, y_count = 1;
	for (const char &c : line) {
		if (c == '<' || c == '>') x_count++;
		else if (c == '^' || c == 'v') y_count++;
	}
	std::vector<std::vector<int> > grid;
	for (unsigned i = 0; i < x_count; i++) {
		std::vector<int> row(y_count, 0);
		grid.push_back(row);
	}
	int current_x = (grid[0].size() % 2 == 0 ? grid[0].size() / 2 + 1 : grid[0].size() / 2);
	int current_y = (grid.size() % 2 == 0 ? grid.size() / 2 + 1 : grid.size() / 2);
	grid[current_y][current_x] = 1;
	int current_x_robo = current_x;
	int current_y_robo = current_y;
	for (unsigned i = 0; i < line.length(); i++) {
		if (i % 2 == 0) {
			if (line[i] == '^') {
				current_y++;
				grid[current_y][current_x]++;
			}
			else if (line[i] == 'v') {
				current_y--;
				grid[current_y][current_x]++;
			}
			else if (line[i] == '>') {
				current_x++;
				grid[current_y][current_x]++;
			}
			else if (line[i] == '<') {
				current_x--;
				grid[current_y][current_x]++;
			}
		}
		else {
			if (line[i] == '^') {
				current_y_robo++;
				grid[current_y_robo][current_x_robo]++;
			}
			else if (line[i] == 'v') {
				current_y_robo--;
				grid[current_y_robo][current_x_robo]++;
			}
			else if (line[i] == '>') {
				current_x_robo++;
				grid[current_y_robo][current_x_robo]++;
			}
			else if (line[i] == '<') {
				current_x_robo--;
				grid[current_y_robo][current_x_robo]++;
			}

		}
	}
	int count = 0;
	for (unsigned i = 0; i < grid.size(); i++) {
		for (unsigned j = 0; j < grid[0].size(); j++) {
			if (grid[i][j] > 0) {
				count++;
			}
		}
	}
	std::cout << count << '\n';
	return 0;
}