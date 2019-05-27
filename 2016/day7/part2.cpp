//#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

bool is_aba(std::string to_test)
{
	return (to_test.at(0) != to_test.at(1))
		&& (to_test.at(0) == to_test.at(2));
}

bool aba_equals_bab(std::string aba, std::string bab)
{
	return ((aba.at(0) == bab.at(1) && (aba.at(1) == bab.at(0)))
		&& aba.at(0) != aba.at(1));
}

int main(int argc, char *argv[])
{
	std::ifstream file("input.txt");
	std::string line;
	int counter = 0;
	while (std::getline(file, line)) {
		bool it_within_brackets = false;
		std::vector<std::string> aba_list, bab_list;
		for (unsigned i = 0; i < line.length() - 2; i++) {
			if (line.substr(i, 3).find('[') != std::string::npos) {
				it_within_brackets = true;
				continue;
			}
			else if (line[i] == ']') {
				it_within_brackets = false;
			}
			if (is_aba(line.substr(i, 3))) {
				if (it_within_brackets) {
					bab_list.push_back(line.substr(i, 3));
				}
				else {
					aba_list.push_back(line.substr(i, 3));
				}
			}
		}
		for (auto aba_it = aba_list.begin(); aba_it != aba_list.end(); aba_it++) {
			bool break_all = false;
			for (auto bab_it = bab_list.begin(); bab_it != bab_list.end(); bab_it++) {
				if (aba_equals_bab(*aba_it, *bab_it)) {
					counter++;
					break_all = true;
					break;
				}
			}
			if (break_all) {
				break;
			}
		}
	}
	std::cout << counter << '\n';
	return 0;
}