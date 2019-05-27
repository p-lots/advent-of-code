#include <algorithm>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <vector>

int main(int argc, char *argv[])
{
	std::vector<int> blocks;
	int temp;
	while (std::cin >> temp)
		blocks.push_back(temp);
	int redis = 0;
	bool finished = false;
	std::set<std::vector<int> > comb_set;
	while (!finished) {
		auto max_elem = std::max_element(blocks.begin(), blocks.end());
		bool inner_finished = false;
		int max_elem_value = *max_elem;
		auto inner_iter = (max_elem + 1 == blocks.end() ? blocks.begin() : max_elem + 1);
		*max_elem = 0;
		while (!inner_finished) {
			*inner_iter += 1;
			max_elem_value--;
			inner_iter++;
			if (inner_iter == blocks.end()) inner_iter = blocks.begin();
			if (max_elem_value == 0) inner_finished = true;
		}
		if (comb_set.count(blocks) == 0) {
			comb_set.insert(blocks);
			redis++;
		}
		else if (comb_set.count(blocks) == 1) {
			finished = true;
		}
	}
	std::cout << redis << '\n';
	return 0;
}

// int sz = blocks.size() - 1
// int each_gets = (*max_elem) / sz;
