#include <iostream>
#include <string>

#include "md5.h"

int main(int argc, char *argv[])
{
	unsigned long long counter = 0;
	unsigned pw_char_counter = 0;
	std::string input = "cxdnnyjw", password = "GGGGGGGG";
	MD5 md5_sum;
	while (pw_char_counter < 8) {
		std::string md5_input = input + std::to_string(counter);
		md5_sum = MD5(md5_input);
		auto hash = md5_sum.hexdigest();
		auto first_five_chars = hash.substr(0, 5);
		if (first_five_chars == "00000") {
			char pos_char = hash.at(5);
			char next_pw_char = hash.at(6);
			unsigned pos = static_cast<int>(pos_char - '0');
			if (pos < 8) {
				if (password[pos] == 'G') {
					password[pos] = next_pw_char;
					pw_char_counter++;
				}
			}
		}
		counter++;
	}
	std::cout << password << '\n';
	return 0;
}