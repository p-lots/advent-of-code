#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

typedef enum {
	NORTH,
	SOUTH,
	EAST,
	WEST
} Direction;

typedef struct {
	int x;
	int y;
} Point;

typedef struct {
	char turn;
	int blocks;
} Instruction;

int main(int argc, char *argv[])
{
	std::ifstream in_file("input.txt");
	std::string temp;
	std::vector<Instruction> instructions;
	while (std::getline(in_file, temp, ' ')) {
		auto comma_pos = temp.find(',');
		char t = temp.at(0);
		int b = std::stoi(temp.substr(1, comma_pos - 1));
		instructions.push_back({ t, b });
	}

	bool board[1000][1000];
	bool break_all = false;
	for (int x = 0; x < 1000; x++) {
		for (int y = 0; y < 1000; y++) {
			board[x][y] = false;
		}
	}
	Point current_pos = { 500, 500 }, second_visit = { 0, 0 };
	Direction current_direction = NORTH;

	for (Instruction inst : instructions) {
		switch (current_direction) {
			case NORTH:
			if (inst.turn == 'L') {
				current_direction = WEST;
				for (int i = 0; i < inst.blocks; i++) {
					if (board[current_pos.x][current_pos.y - i] == true) {
						break_all = true;
						second_visit = { current_pos.x, current_pos.y - i };
						break;
					}
					board[current_pos.x][current_pos.y - i] = true;
				}
				current_pos.y -= inst.blocks;
			}
			else if (inst.turn == 'R') {
				current_direction = EAST;
				for (int i = 0; i < inst.blocks; i++) {
					if (board[current_pos.x][current_pos.y + i] == true) {
						break_all = true;
						second_visit = { current_pos.x, current_pos.y + i };
						break;
					}
					board[current_pos.x][current_pos.y + i] = true;
				}
				current_pos.y += inst.blocks;
			}
			break;
			case SOUTH:
			if (inst.turn == 'L') {
				current_direction = EAST;
				for (int i = 0; i < inst.blocks; i++) {
					if (board[current_pos.x][current_pos.y + i] == true) {
						break_all = true;
						second_visit = { current_pos.x, current_pos.y + i };
						break;
					}
					board[current_pos.x][current_pos.y + i] = true;
				}
				current_pos.y += inst.blocks;
			}
			else if (inst.turn == 'R') {
				current_direction = WEST;
				for (int i = 0; i < inst.blocks; i++) {
					if (board[current_pos.x][current_pos.y - i] == true) {
						break_all = true;
						second_visit = { current_pos.x, current_pos.y - i };
						break;
					}
					board[current_pos.x][current_pos.y - i] = true;
				}
				current_pos.y -= inst.blocks;
			}
			break;
			case EAST:
			if (inst.turn == 'L') {
				current_direction = NORTH;
				for (int i = 0; i < inst.blocks; i++) {
					if (board[current_pos.x + i][current_pos.y] == true) {
						break_all = true;
						second_visit = { current_pos.x + i, current_pos.y };
						break;
					}
					board[current_pos.x + i][current_pos.y] = true;
				}
				current_pos.x += inst.blocks;
			}
			else if (inst.turn == 'R') {
				current_direction = SOUTH;
				for (int i = 0; i < inst.blocks; i++) {
					if (board[current_pos.x - i][current_pos.y] == true) {
						break_all = true;
						second_visit = { current_pos.x - i, current_pos.y };
						break;
					}
					board[current_pos.x - i][current_pos.y] = true;
				}
				current_pos.x -= inst.blocks;
			}
			break;
			case WEST:
			if (inst.turn == 'L') {		
				current_direction = SOUTH;
				for (int i = 0; i < inst.blocks; i++) {
					if (board[current_pos.x - i][current_pos.y] == true) {
						break_all = true;
						second_visit = { current_pos.x - i, current_pos.y };
						break;
					}
					board[current_pos.x - i][current_pos.y] = true;
				}
				current_pos.x -= inst.blocks;
			}
			else if (inst.turn == 'R') {
				current_direction = NORTH;
				for (int i = 0; i < inst.blocks; i++) {
					if (board[current_pos.x + i][current_pos.y] == true) {
						break_all = true;
						second_visit = { current_pos.x + i, current_pos.y };
						break;
					}
					board[current_pos.x + i][current_pos.y] = true;
				}
				current_pos.x += inst.blocks;
			}
			break;
			default:
			throw std::invalid_argument("Invalid direction encountered");
			break;
		}
		if (break_all) {
			break;
		}
	}


	//int distance = std::abs(current_pos.x - current_pos.y);

	int distance = std::abs(second_visit.x - second_visit.y);

	std::cout << distance << '\n';

	return 0;
}