#include <string.h>
#include <algorithm>
#include <functional>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

const int MAX_ELEM = 987654321;

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
	if (n == 10)
	{
		if (all_of(clock.begin(), clock.end(), 
					[](int k) { return k % 4 == 0; }))
			return c;
		return MAX_ELEM;
	}

	int ret = MAX_ELEM;
	for (int i = 0; i < 4; i++)
	{
		set(clock, S[n], i);
		ret = min(ret, sync(clock, n+1, c+i));
		reset(clock, S[n], i);
	}
	return ret;
}

int main()
{
#if _DEBUG
	ifstream fin("clocksync.in");
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
		int ret = sync(clock, 0, 0);
		if (ret == MAX_ELEM)
			ret = -1;
		cout << ret << endl;
	}
	
	return 0;
}

