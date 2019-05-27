#include <cmath>
#include <cctype>
#include <deque>
#include <iostream>
#include <string>

int main()
{
	std::string input;
	std::getline(std::cin, input);
	unsigned long min_len = input.length();
	for (unsigned i = 0; i < 26; i++) {
		bool finished = false;
		auto line = input;
		while (!finished) {
			std::deque<char> dq;
			for (const char &c : line) {
				if (c == static_cast<char>(i + 'a') || c == static_cast<char>(i + 'A')) continue;
				dq.push_back(c);
			}
			bool found_match = false;
			std::string line_next;
			while (dq.size() > 0) {
				char curr = dq.front();
				dq.pop_front();
				if (dq.size() == 0) {
					line_next.push_back(curr);
					break;
				}
				if (std::isupper(curr)) {
					curr = std::tolower(curr);
					if (curr == dq.front()) {
						dq.pop_front();
						found_match = true;
					}
					else {
						line_next.push_back(std::toupper(curr));
					}
				}
				else {
					curr = std::toupper(curr);
					if (curr == dq.front()) {
						dq.pop_front();
						found_match = true;
					}
					else {
						line_next.push_back(std::tolower(curr));
					}
				}
			}
			line = line_next;
			finished = !found_match;
		}
		min_len = std::min(min_len, line.length());
	}
	std::cout << min_len << '\n';
	return 0;
}