#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#define BOARD_WIDTH 7
#define BOARD_HEIGHT 3

std::vector<std::string> tokenize(std::string);

void parse_tokens(bool[BOARD_HEIGHT][BOARD_WIDTH], std::vector<std::string>);

int main(int argc, char *argv[])
{
	std::ifstream file("test1.txt");
	std::string line;
	bool board[BOARD_HEIGHT][BOARD_WIDTH];
	for (unsigned i = 0; i < BOARD_HEIGHT; i++) {
		for (unsigned j = 0; j < BOARD_WIDTH; j++) {
			board[i][j] = false;
		}
	}
	while (std::getline(file, line)) {
		std::vector<std::string> tokens = tokenize(line);
		parse_tokens(board, tokens);
	}
	for (unsigned i = 0; i < BOARD_HEIGHT; i++) {
		for (unsigned j = 0; j < BOARD_WIDTH; j++) {
			if (board[i][j]) {
				std::cout << '#';
			}
			else {
				std::cout << '.';
			}
		}
		std::cout << '\n';
	}
	std::cout << '\n';
	return 0;
}

std::vector<std::string> tokenize(std::string line)
{
	std::vector<std::string> ret;
	std::stringstream ss(line);
	std::string temp;
	while (std::getline(ss, temp, ' ')) {
		ret.push_back(temp);
	}
	return ret;
}

void parse_tokens(bool board[BOARD_HEIGHT][BOARD_WIDTH], std::vector<std::string> tokens)
{
	if (tokens.front() == "rect") {
		auto dimensions = tokens.at(1);
		auto delim_pos = dimensions.find('x');
		int width = std::stoi(dimensions.substr(0, delim_pos));
		int height = std::stoi(dimensions.substr(delim_pos + 1));
		for (unsigned i = 0; i < height; i++) {
			for (unsigned j = 0; j < width; j++) {
				board[i][j] = true;
			}
		}
	}
	else if (tokens.front() == "rotate") {
		std::cout << "rotate\n";
		if (tokens.at(1) == "column") {
			std::cout << "column\n";
			auto column_str = tokens.at(2);
			int column_n = std::stoi(column_str.substr(column_str.find('=') + 1));
			int amount_to_rotate = std::stoi(tokens.back());
			for (unsigned i = 0; i < BOARD_HEIGHT; i++) {
				//for (unsigned j = 0; j < BOARD_WIDTH; j++) {
					//int safe_column = ((i + amount_to_rotate) % BOARD_HEIGHT);
					int safe_column = i + amount_to_rotate;
					if (safe_column > BOARD_HEIGHT) {
						safe_column %= BOARD_HEIGHT;
					}
					bool temp = board[i][column_n];
					board[i][column_n] = board[i][safe_column];
					board[i][safe_column] = temp;
				//}
			}
		}
		else { // row
			//
		}
	}
}