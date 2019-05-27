#include <cctype>
#include <fstream>
#include <iostream>
#include <string>

typedef struct {
	unsigned length;
	unsigned repetitions;
} Repeat;

unsigned long long parse_line(std::string);

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

unsigned long long parse_line(std::string line)
{
	//std::cout << "Parsing <" << line << ">\n";
	unsigned i = 0;
	unsigned long long ret = 0;
	while (i < line.length()) {
		if (std::isspace(line.at(i))) {
			i++;
		}
		else if (line.at(i) == '(') {
			//std::cout << "Found open paren\n";
			auto end_paren = line.find(')', i);
			auto paren_str = line.substr(i, (end_paren + 1) - i);
			//std::cout << "paren_str: <" << paren_str << ">\n";
			Repeat r = parse_parens(paren_str);
			//std::cout << "Repeat length: " << r.length << '\n';
			//std::cout << "Repeat # of reps: " << r.repetitions << '\n';
			if (line.substr(end_paren + 1, r.length).find('(') != std::string::npos) {
				ret += r.repetitions * parse_line(line.substr(end_paren + 1, r.length));
			}
			else {
				//std::cout << "Increasing ret by " << r.length * r.repetitions << '\n';
				ret += r.length * r.repetitions;
				//std::cout << "ret = " << ret << '\n';
			}
			i += paren_str.length() + r.length;
		}
		else {
			ret++;
			i++;
		}
	}
	//std::cout << "Leaving parse_line, ret = " << ret << '\n';
	return ret;
}

Repeat parse_parens(std::string parens)
{
	//unsigned ret;
	Repeat rep;
	auto x_pos = parens.find('x'), end_paren = parens.find(')');
	rep.length = std::stoi(parens.substr(1, x_pos));
	rep.repetitions = std::stoi(parens.substr(x_pos + 1, end_paren));
	//if (parens.substr(end_paren + 1, rep.length).find('(') != std::string::npos) {
	//	ret += parse_parens(parens.substr(parens.find('(', end_paren)));
	//}
	//else {
	//	return rep.length * rep.repetitions;
	//}
	return rep;
}