#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

int calculate_length(vector<int>& input)
{
	sort(input.begin(), input.end());

	int p = input[0] + input[0] + input[1] + input[1];

	int v = input[0] * input[1] * input[2];

	return p + v;
}

void get_numbers(string line, vector<int>& output)
{
	stringstream ss(line);
	string temp;
	
	while (getline(ss, temp, 'x')) 
		output.push_back(stoi(temp));
}

int main(int argc, char *argv[])
{
	ifstream file(argv[1]);
	string line;
	int total = 0;

	while (getline(file, line)) {
		vector<int> nums;
		get_numbers(line, nums);

		int len = calculate_length(nums);
		total += len;
	}

	cout << total << endl;

	return 0;
}