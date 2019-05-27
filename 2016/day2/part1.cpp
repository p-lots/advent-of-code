#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

typedef struct {
	int x;
	int y;
} Point;

int main(int argc, char *argv[])
{
	int keypad[3][3] = {
		{ 1, 2, 3 },
		{ 4, 5, 6 },
		{ 7, 8, 9 }
	};
	std::string instructions = "ULL\n"
		"RRDDD\n"
		"LURDL\n"
		"UUUUD";
	Point start = { 1, 1 }, current = { 1, 1 };
	//std::stringstream ss(instructions);
	std::ifstream ss("input.txt");
	std::string temp;
	std::vector<int> result;
	while (std::getline(ss, temp)) {
		for (char c : temp) {
			if (c == 'R' && current.y < 2) {
				current.y++;
			}
			else if (c == 'L' && current.y > 0) {
				current.y--;
			}
			else if (c == 'U' && current.x > 0) {
				current.x--;
			}
			else if (c == 'D' && current.x < 2) {
				current.x++;
			}
		}
		result.push_back(keypad[current.x][current.y]);
	}
	for (int n : result) {
		std::cout << n;
	}
	std::cout << '\n';
	return 0;
}