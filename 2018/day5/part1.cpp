#include <cctype>
#include <deque>
#include <iostream>
#include <string>

int main()
{
	std::string line;
	while (std::getline(std::cin, line)) {
		bool finished = false;
		while (!finished) {
			std::deque<char> dq;
			for (const char &c : line) {
				dq.push_back(c);
			}
			bool found_match = false;
			std::string line_next;
			while (dq.size() > 0) {
				char curr = dq.front();
				dq.pop_front();
				if (std::isupper(curr)) {
					curr = std::tolower(curr);
					if (curr == dq.front()) {
						dq.pop_front();
						found_match = true;
					}
					else {
						line_next.push_back(std::toupper(curr));
						//dq.pop_front();
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
						//dq.pop_front();
					}
				}
			}
			line = line_next;
			finished = !found_match;
		}
		//std::cout << "line: " << line << '\n';
		std::cout << line.length() << '\n';
	}
	return 0;
}