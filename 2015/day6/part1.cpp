#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

struct Coords {
	int x1;
	int y1;
	int x2;
	int y2;
};

void get_coords(string coords1, string coords2, Coords& coordinates)
{
	stringstream ss(coords1);
	string temp;
	bool firstTime = true;

	while (getline(ss, temp, ',')) {
		if (firstTime) {
			coordinates.x1 = stoi(temp);
			firstTime = false;
		}

		else
			coordinates.y1 = stoi(temp);
	}

	firstTime = true;
	stringstream sss(coords2);
	string ttt;

	while (getline(sss, ttt, ',')) {
		if (firstTime) {
			coordinates.x2 = stoi(ttt);
			firstTime = false;
		}

		else
			coordinates.y2 = stoi(ttt);
	}
}

void split_line(string line, vector<string>& output)
{
	stringstream ss(line);
	string temp;

	while (getline(ss, temp, ' '))
		output.push_back(temp);
}

int main(int argc, char *argv[])
{
	int grid[1000][1000];

	for (int i = 0; i < 1000; ++i) {
		for (int j = 0; j < 1000; ++j) {
			grid[i][j] = 0;
		}
	}

	ifstream file(argv[1]);
	string line;
	int onCount = 0;

	while (getline(file, line)) {
		vector<string> contents;

		split_line(line, contents);

		string coords1, coords2;

		bool toggleFlag = false, offFlag = false, onFlag = false;

		if (contents[0].compare("toggle") == 0) {
			coords1 = contents[1];
			coords2 = contents[3];
			toggleFlag = true;
		}

		else if (contents[1].compare("off") == 0) {
			coords1 = contents[2];
			coords2 = contents[4];
			offFlag = true;
		}

		else if (contents[1].compare("on") == 0) {
			coords1 = contents[2];
			coords2 = contents[4];
			onFlag = true;
		}
		
		Coords coordinates;

		get_coords(coords1, coords2, coordinates);

		
		for (int i = coordinates.x1; i <= coordinates.x2; ++i) {
			for (int j = coordinates.y1; j <= coordinates.y2; ++j) {
				if (toggleFlag) {
					if (grid[i][j] == 0) {
						grid[i][j] = 1;
					}
					else {
						grid[i][j] = 0;
					}
				}
				else if (offFlag)
					grid[i][j] = 0;
				else if (onFlag)
					grid[i][j] = 1;
			}
		}
	}

	for (int i = 0; i < 1000; ++i) {
		for (int j = 0; j < 1000; ++j) {
			if (grid[i][j] == 1)
				onCount++;
		}
	}

	cout << onCount << endl;

	return 0;
}