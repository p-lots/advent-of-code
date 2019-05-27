#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

typedef struct {
	int x;
	int y;
} Point;

int main(int argc, char *argv[])
{
	char keypad[5][5] = {
		{ '0', '0', '1', '0', '0' },
		{ '0', '2', '3', '4', '0' },
		{ '5', '6', '7', '8', '9' },
		{ '0', 'A', 'B', 'C', '0' },
		{ '0', '0', 'D', '0', '0' }
	};
	std::string instructions = "ULL\n"
		"RRDDD\n"
		"LURDL\n"
		"UUUUD";
	Point current = { 2, 0 };
	//std::cout << keypad[current.x][current.y] << '\n';
	//std::stringstream ss(instructions);
	std::ifstream ss("input.txt");
	std::string temp;
	std::vector<char> result;
	while (std::getline(ss, temp)) {
		for (char c : temp) {
			if (c == 'R') {
				switch (current.x) {
					case 0:
					case 4:
					break;
					case 1:
					case 3:
					if (current.y == 1 || current.y == 2) {
						current.y++;
					}
					break;
					case 2:
					if (current.y >= 0 && current.y <= 3) {
						current.y++;
					}
					break;
					default:
					throw std::domain_error("Invalid range encountered");
					break;
				}
			}
			else if (c == 'L') {
				switch (current.x) {
					case 0:
					case 4:
					break;
					case 1:
					case 3:
					if (current.y == 2 || current.y == 3) {
						current.y--;
					}
					break;
					case 2:
					if (current.y >= 1 && current.y <= 4) {
						current.y--;
					}
					break;
					default:
					throw std::domain_error("Invalid range encountered");
					break;
				}
			}
			else if (c == 'U') {
				switch (current.y) {
					case 0:
					case 4:
					break;
					case 1:
					case 3:
					if (current.x == 2 || current.x == 3) {
						current.x--;
					}
					break;
					case 2:
					if (current.x >= 1 && current.x <= 4) {
						current.x--;
					}
					break;
					default:
					throw std::domain_error("Invalid range encountered");
					break;
				}
			}
			else if (c == 'D') {
				switch (current.y) {
					case 0:
					case 4:
					break;
					case 1:
					case 3:
					if (current.x == 1 || current.x == 2) {
						current.x++;
					}
					break;
					case 2:
					if (current.x >= 0 && current.x <= 3) {
						current.x++;
					}
					break;
					default:
					throw std::domain_error("Invalid range encountered");
					break;
				}
			}
		}
		result.push_back(keypad[current.x][current.y]);
	}
	for (char n : result) {
		std::cout << n;
	}
	std::cout << '\n';
	return 0;
}