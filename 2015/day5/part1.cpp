#include <iostream>
#include <string>

bool has_three_vowels(std::string line)
{
	int vowel_count = 0;
	for (const char &c : line)
		if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
			vowel_count++;
	return vowel_count >= 3;
}

bool has_two_letters_in_a_row(std::string line)
{
	for (unsigned i = 0; i < line.length() - 1; ++i)
		if (line[i] == line[i + 1])
			return true;
	return false;
}

bool contains_no_forbidden_strings(std::string line)
{
	if ((line.find("ab") != std::string::npos)
		|| (line.find("cd") != std::string::npos)
		|| (line.find("pq") != std::string::npos)
		|| (line.find("xy") != std::string::npos))
		return false;
	return true;
}

int main(int argc, char *argv[])
{
	std::string line;
	int nice_count = 0;
	while (std::getline(std::cin, line)) {
		if (has_three_vowels(line)
			&& has_two_letters_in_a_row(line)
			&& contains_no_forbidden_strings(line)) {
			nice_count++;
		}
	}
	std::cout << nice_count << '\n';
	return 0;
}