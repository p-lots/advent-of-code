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
	//std::vector<std::string> tokens;
	std::vector<Instruction> instructions;
	//int counter = 1;
	while (std::getline(in_file, temp, ' ')) {
	//	counter++;
		auto comma_pos = temp.find(',');
	//	tokens.push_back(temp.substr(0, comma_pos));
		char t = temp.at(0);
		int b = std::stoi(temp.substr(1, comma_pos - 1));
		instructions.push_back({ t, b });
	}

	//std::cout << counter << " directions in input\n";

	//std::vector<std::string> test_input = { "R5", "L5", "R5", "R3" };

	Point current_pos = { 0, 0 };
	Direction current_direction = NORTH;
	//counter = 1;

	//for (std::string str : tokens) {
	for (Instruction inst : instructions) {
		switch (current_direction) {
			case NORTH:
			//std::cout << "current direction is north\n";
			//if (str.at(0) == 'L') {
			if (inst.turn == 'L') {
			//	std::cout << "found L, turning west\n";
				current_direction = WEST;
				current_pos.y -= inst.blocks;
			//	std::cout << "current x: " << current_pos.x << " current y: " << current_pos.y << '\n';
			}
			//else if (str.at(0) == 'R') {
			else if (inst.turn == 'R') {
			//	std::cout << "found R, turning east\n";
				current_direction = EAST;
				current_pos.y += inst.blocks;
			//	std::cout << "current x: " << current_pos.x << " current y: " << current_pos.y << '\n';
			}
			break;
			case SOUTH:
			//std::cout << "current direction is south\n";
			//if (str.at(0) == 'L') {
			if (inst.turn == 'L') {
			//	std::cout << "found L, turning east\n";
				current_direction = EAST;
				current_pos.y += inst.blocks;
			//	std::cout << "current x: " << current_pos.x << " current y: " << current_pos.y << '\n';
			}
			//else if (str.at(0) == 'R') {
			else if (inst.turn == 'R') {
			//	std::cout << "found R, turning west\n";
				current_direction = WEST;
				current_pos.y -= inst.blocks;
			//	std::cout << "current x: " << current_pos.x << " current y: " << current_pos.y << '\n';
			}
			break;
			case EAST:
			//std::cout << "current direction is east\n";
			//if (str.at(0) == 'L') {
			if (inst.turn == 'L') {
			//	std::cout << "found L, turning north\n";
				current_direction = NORTH;
				current_pos.x += inst.blocks;
			//	std::cout << "current x: " << current_pos.x << " current y: " << current_pos.y << '\n';
			}
			//else if (str.at(0) == 'R') {
			else if (inst.turn == 'R') {
			//	std::cout << "found R, turning south\n";
				current_direction = SOUTH;
				current_pos.x -= inst.blocks;
			//	std::cout << "current x: " << current_pos.x << " current y: " << current_pos.y << '\n';
			}
			break;
			case WEST:
			//std::cout << "current direction is west\n";
			//if (str.at(0) == 'L') {
			if (inst.turn == 'L') {		
			//	std::cout << "found L, turning south\n";
				current_direction = SOUTH;
				current_pos.x -= inst.blocks;
			//	std::cout << "current x: " << current_pos.x << " current y: " << current_pos.y << '\n';
			}
			//else if (str.at(0) == 'R') {
			else if (inst.turn == 'R') {
			//	std::cout << "found R, turning north\n";
				current_direction = NORTH;
				current_pos.x += inst.blocks;
			//	std::cout << "current x: " << current_pos.x << " current y: " << current_pos.y << '\n';
			}
			break;
			default:
			throw std::invalid_argument("Invalid direction encountered");
			break;
		}
		//counter++;
	}


	//std::cout << counter << " directions processed\n";
	int distance = std::abs(current_pos.x - current_pos.y);

	std::cout << distance << '\n';

	return 0;
}