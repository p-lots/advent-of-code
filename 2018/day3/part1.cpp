#include <iostream>
#include <string>
#include <vector>

typedef struct {
	unsigned x;
	unsigned y;
	unsigned w;
	unsigned h;
} Claim;

int main()
{
	std::string line;
	std::vector<Claim> claims;
	while (std::getline(std::cin, line)) {
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
		Claim c{ x, y, w, h };
		claims.push_back(c);
	}
	std::vector<std::vector<int>> grid;
	for (unsigned i = 0; i < 1024; i++) {
		std::vector<int> temp = std::vector<int>(1024, 0);
		grid.push_back(temp);
	}
	for (const Claim &claim : claims) {
		for (unsigned i = claim.x; i < claim.x + claim.w; i++) {
			for (unsigned j = claim.y; j < claim.y + claim.h; j++) {
				grid[i][j]++;
			}
		}
	}
	unsigned count = 0;
	for (unsigned i = 0; i < grid.size(); i++) {
		for (unsigned j = 0; j < grid[0].size(); j++) {
			if (grid[i][j] > 1) count++;
		}
	}
	std::cout << count << '\n';
	return 0;
}