#include <string.h>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

vector<int> S[10] = {
	{0, 1, 2},
	{3, 7, 9, 11},
	{4, 10, 14, 15},
	{0, 4, 5, 6, 7},
	{6, 7, 8, 10, 12},
	{0, 2, 14, 15},
	{3, 14, 15},
	{4, 5, 7, 14, 15},
	{1, 2, 3, 4, 5},
	{3, 4, 5, 9, 13},
};

vector<pair<int, int>> M = {
	{ 13, 9 },
	{ 12, 4 },
	{ 11, 1 },
	{ 10, 2 },
	{ 19, 7 },
	{ 6, 3 },
	{ 14, 5 },
	{ 5, 8 },
	{ 1, 0 },
	{ 3, 6 },
};

void set(vector<int>& clock, vector<int>& s, int count)
{
	for (int i = 0; i < s.size(); i++)
	{
		clock[s[i]] -= count;
	}
}

void reset(vector<int>& clock, vector<int>& s, int count)
{
	set(clock, s, -count);
}

int sync(vector<int>& clock, int n, int c)
{
	for (int i = 0; i < clock.size(); i++)
		clock[i] = (clock[i] + 4) % 4;

	if (n == 10)
		return c;

	if (clock[n] == 0)
		return sync(clock, n+1, c);

	int count = clock[M[n].first];

	set(clock, S[M[n].second], count);

	return sync(clock, n+1, c+count);
}

int main()
{
#if 1//_DEBUG
	ifstream fin("input.txt");
	istream& in = fin;
#else
	istream& in = cin;
#endif

	int C, T;
	in >> C;

	while (C--)
	{
		vector<int> clock(16);
		for (auto & e : clock)
		{
			in >> T;
			e = (4 - T/3);
		}

		int result = sync(clock, 0, 0);
		auto it = max_element(clock.begin(), clock.end());
		if (*it != 0)
			result = -1;

		cout << result << endl;
	}
	
	return 0;
}

