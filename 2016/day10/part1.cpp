#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

typedef struct {
	int number;
	int first_starting_chip;
	int second_starting_chip;
	int gives_low_to;
	int gives_high_to;
	int held_chip_low;
	int held_chip_high;
	int number_of_held_chips;
} Bot;

std::vector<Bot> bots;

std::vector<std::string> tokenize(std::string line)
{
	std::stringstream ss(line);
	std::string temp;
	std::vector<std::string> ret;
	while (std::getline(ss, temp, ' ')) {
		ret.push_back(temp);
	}
	return ret;
}

std::vector<Bot>::iterator find_bot(int bot_number)
{
	std::vector<Bot>::iterator ret = bots.end();
	for (auto it = bots.begin(); it != bots.end(); it++) {
		if (it->number == bot_number) {
			ret = it;
			break;
		}
	}
	return ret;
}

std::vector<Bot>::iterator find_answer()
{
	std::vector<Bot>::iterator ret = bots.end();
	for (auto it = bots.begin(); it != bots.end(); it++) {
		if (it->held_chip_low == 17 && held_chip_high == 61) {
			ret = it;
			break;
		}
	}
	return ret;
}

void initialize_bot(Bot &bot)
{
	bot.number = -1;
	bot.first_starting_chip = -1;
	bot.second_starting_chip = -1;
	bot.gives_low_to = -1;
	bot.gives_high_to = -1;
	bot.held_chip_low = -1;
	bot.held_chip_high = -1;
	bot.number_of_held_chips = -1;
}

int main(int argc, char *argv[])
{
	std::ifstream file("test.txt");
	std::string line;
	while (std::getline(file, line)) {
		auto tokens = tokenize(line);
		Bot temp_bot;
		initialize_bot(temp_bot);
		if (tokens.front() == "value") {
			int bot_number = std::stoi(tokens.back());
			auto it = find_bot(bot_number);
			if (it == bots.end()) {
				temp_bot.first_starting_chip = std::stoi(tokens.at(1));
				temp_bot.number = std::stoi(tokens.back());
				temp_bot.number_of_held_chips = 1;
				bots.push_back(temp_bot);
				//continue;
			}
			else {
				if (it->first_starting_chip == -1) {
					it->first_starting_chip = std::stoi(tokens.at(1));
				}
				else {
					it->second_starting_chip = std::stoi(tokens.at(1));
					it->number_of_held_chips++;
				}
				//continue;
			}
			//continue;
		}
		else if (tokens.front() == "bot") {
			auto it = find_bot(std::stoi(tokens.at(2)));
			if (it != bots.end()) {
				
			}
		}
	}
	std::sort(bots.begin(), bots.end(), [](Bot lhs, Bot rhs) {
		return lhs.number < rhs.number;
	});
	for (Bot b : bots) {
		std::cout << "bot number: " << b.number << '\n';
		std::cout << "bot chip #1: " << b.first_starting_chip << '\n';
		std::cout << "bot chip #2: " << b.second_starting_chip << '\n';
		std::cout << std::string(15, '=') << '\n';
	}
	return 0;
}

/*
 * parse line
 * 
 * 
*/