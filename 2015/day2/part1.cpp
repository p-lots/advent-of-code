#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

int calculate_area(vector<int>& input)
{
	int l, w, h, a, s, calcL, calcW, calcH;
	vector<int> nums;
	l = input[0];
	w = input[1];
	h = input[2];
	calcL = 2 * l * w;
	calcW = 2 * w * h;
	calcH = 2 * h * l;
	nums.push_back(calcL / 2);
	nums.push_back(calcW / 2);
	nums.push_back(calcH / 2);
	a = calcL + calcW + calcH;
	
	s = nums[0];
	for (int i = 0; i < 3; ++i) {
		if (nums[i] < s)
			s = nums[i];
	}

	a += s;

	return a;
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

		int area = calculate_area(nums);
		total += area;
	}

	cout << total << endl;

	return 0;
}