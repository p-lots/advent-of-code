#include <iostream>
#include <string>

#include "md5.h"

int main(int argc, char *argv[])
{
	unsigned long long counter = 0;
	std::string input = "cxdnnyjw", password = "";
	char next_pw_char = '\x00';
	MD5 md5_sum;
	while (password.length() < 9) {
		std::string md5_input = input + std::to_string(counter);
		md5_sum = MD5(md5_input);
		auto hash = md5_sum.hexdigest();
		auto first_five_chars = hash.substr(0, 5);
		if (first_five_chars == "00000") {
			next_pw_char = hash.at(5);
		}
		if (next_pw_char != '\x00') {
			password += next_pw_char;
		}
		next_pw_char = '\x00';
		counter++;
	}
	std::cout << password << '\n';
	return 0;
}