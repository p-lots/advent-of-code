#include <cctype>
#include <fstream>
#include <iostream>
#include <string>

typedef struct {
	unsigned length;
	unsigned repetitions;
} Repeat;

std::string::size_type parse_line(std::string);

Repeat parse_parens(std::string);

int main(int argc, char *argv[])
{
	std::ifstream file("input.txt");
	std::string line;
	std::getline(file, line);
	auto result = parse_line(line);
	std::cout << result << '\n';
	return 0;
}

std::string::size_type parse_line(std::string line)
{
	Repeat r = { 0, 0 };
	std::string result;
	unsigned i = 0;
	while (i < line.length()) {
		if (std::isspace(line.at(i))) {
			i++;
		}
		else if (line.at(i) == '(') {
			auto end_paren = line.find(')', i);
			r = parse_parens(line.substr(i + 1, end_paren - i));
			for (unsigned counter = 0; counter < r.repetitions; counter++) {
				result += line.substr(end_paren + 1, r.length);
			}
			i += (end_paren + 1) - i + r.length;
		}
		else {
			result.push_back(line.at(i));
			i++;
		}
	}
	return result.length();
}

Repeat parse_parens(std::string parens)
{
	Repeat ret;
	auto x_pos = parens.find('x');
	ret.length = std::stoi(parens.substr(0, x_pos));
	ret.repetitions = std::stoi(parens.substr(x_pos + 1));
	return ret;
}