#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

std::vector<std::string> tokenize(std::string line)
{
	std::vector<std::string> ret;
	std::stringstream ss(line);
	std::string temp;
	while (std::getline(ss, temp, ' '))
		ret.push_back(temp);
	return ret;
}

int main(int argc, char *argv[])
{
	std::string line;
	std::vector<std::vector<std::string> > instructions;
	while (std::getline(std::cin, line)) {
		auto tokens = tokenize(line);
		instructions.push_back(tokens);
	}
	std::map<std::string, int> regs;
	for (const auto &inst : instructions) {
		regs[inst[0]] = 0;
	}
	for (const auto &inst : instructions) {
		auto reg_to_change = inst[0];
		auto inc_or_dec = inst[1];
		auto val_to_inc_dec = std::stoi(inst[2]);
		auto reg_to_compare = inst[4];
		auto op = inst[5];
		auto val_to_compare = std::stoi(inst[6]);
		if (op == "<") {
			if (regs[reg_to_compare] < val_to_compare) {
				if (inc_or_dec == "inc")
					regs[reg_to_change] += val_to_inc_dec;
				else
					regs[reg_to_change] -= val_to_inc_dec;
			}
		}
		else if (op == ">") {
			if (regs[reg_to_compare] > val_to_compare) {
				if (inc_or_dec == "inc") 
					regs[reg_to_change] += val_to_inc_dec;
				else
					regs[reg_to_change] -= val_to_inc_dec;
			}
		}
		else if (op == "<=") {
			if (regs[reg_to_compare] <= val_to_compare) {
				if (inc_or_dec == "inc")
					regs[reg_to_change] += val_to_inc_dec;
				else
					regs[reg_to_change] -= val_to_inc_dec;
			}
		}
		else if (op == ">=") {
			if (regs[reg_to_compare] >= val_to_compare) {
				if (inc_or_dec == "inc")
					regs[reg_to_change] += val_to_inc_dec;
				else
					regs[reg_to_change] -= val_to_inc_dec;
			}
		}
		else if (op == "!=") {
			if (regs[reg_to_compare] != val_to_compare) {
				if (inc_or_dec == "inc")
					regs[reg_to_change] += val_to_inc_dec;
				else
					regs[reg_to_change] -= val_to_inc_dec;
			}
		}
		else if (op == "==") {
			if (regs[reg_to_compare] == val_to_compare) {
				if (inc_or_dec == "inc")
					regs[reg_to_change] += val_to_inc_dec;
				else
					regs[reg_to_change] -= val_to_inc_dec;
			}
		}
	}
    auto result = std::max_element(regs.begin(), regs.end(),
    	[](const auto &lhs, const auto &rhs) {
        	return lhs.second < rhs.second;
	    });
    std::cout << result->second << '\n';
	return 0;
}