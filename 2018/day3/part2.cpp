#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>

typedef struct {
	unsigned number;
	unsigned x;
	unsigned y;
	unsigned w;
	unsigned h;
} Claim;

typedef struct {
	unsigned count;
	std::vector<unsigned> numbers;
} Cell;

int main()
{
	std::string line;
	std::vector<Claim> claims;
	while (std::getline(std::cin, line)) {
		auto first_space = line.find(" ");
		auto number_str = line.substr(1, first_space - 1);
		unsigned number = std::stoi(number_str);
		auto comma_pos = line.find(",");
		auto space_before_comma_pos = line.find_last_of(" ", comma_pos);
		auto x_str = line.substr(space_before_comma_pos + 1, comma_pos - space_before_comma_pos - 1);
		unsigned x = std::stoi(x_str);
		auto colon_pos = line.find(":");
		auto y_str = line.substr(comma_pos + 1, colon_pos - comma_pos - 1);
		unsigned y = std::stoi(y_str);
		auto last_space_pos = line.find_last_of(" ");
		auto x_sep_pos = line.find("x");
		auto w_str = line.substr(last_space_pos + 1, x_sep_pos - last_space_pos - 1);
		unsigned w = std::stoi(w_str);
		auto h_str = line.substr(x_sep_pos + 1);
		unsigned h = std::stoi(h_str);
		Claim c{ number, x, y, w, h };
		claims.push_back(c);
	}
	std::vector<std::vector<Cell>> grid;
	std::vector<unsigned> temp_cell_vec;
	Cell temp_cell{ 0, temp_cell_vec };
	for (unsigned i = 0; i < 1024; i++) {
		std::vector<Cell> temp = std::vector<Cell>(1024, temp_cell);
		grid.push_back(temp);
	}
	std::set<unsigned> claim_set;
	for (const Claim &claim : claims) {
		claim_set.insert(claim.number);
		for (unsigned i = claim.x; i < claim.x + claim.w; i++) {
			for (unsigned j = claim.y; j < claim.y + claim.h; j++) {
				grid[i][j].count++;
				grid[i][j].numbers.push_back(claim.number);
			}
		}
	}
	for (const Claim &claim : claims) {
		for (unsigned i = claim.x; i < claim.x + claim.w; i++) {
			for (unsigned j = claim.y; j < claim.y + claim.h; j++) {
				if (grid[i][j].count > 1) {
					for (const unsigned &n : grid[i][j].numbers) {
						auto it = std::find(claim_set.begin(), claim_set.end(), n);
						if (it != claim_set.end()) claim_set.erase(it);
					}
				}
			}
		}
	}
	for (const auto &num : claim_set) {
		std::cout << num << '\n';
	}
	return 0;
}