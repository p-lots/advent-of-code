#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{
	ifstream file(argv[1]);
	string line;

	while (getline(file, line)) {
		int val = 0;
		string::size_type i = 0;

		while (val >= 0 && i < line.length())
		{
			if (line[i] == '(')
				++val;
			else if (line[i] == ')')
				--val;
			++i;
		}

		cout << i << endl;
	}

	return 0;
}