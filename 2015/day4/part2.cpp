#include "md5.h"
#include <iostream>
#include <climits>
#include <string>

int main(int argc, char *argv[])
{
	for (unsigned long long i = 0; i < ULLONG_MAX; i++) {
		std::string md5test = md5("iwrupvqb" + std::to_string(i));
		if (md5test[0] == '0' && md5test[1] == '0' && md5test[2] == '0' && md5test[3] == '0' &&
			md5test[4] == '0' && md5test[5] == '0') {
			std::cout << "Found value: " << i << '\n';
			break;
		}
	}

	return 0;
}