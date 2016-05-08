#include <iostream>
#include <assert.h>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <string.h>

using namespace std;

vector<string> M(5);

string w;
int cache[5][5][11];

bool hasWord(int y, int x, int n)
{
	if (y < 0 || y >= 5) return false;
	if (x < 0 || x >= 5) return false;

	if (n == w.size())
		return true;

	int& ret = cache[y][x][n];
	if (ret != -1)
		return ret;
	
	if (M[y][x] != w[n])
		return ret = 0;

	int yy[8] = { -1, -1, -1,  0,  0,  1, 1, 1 };
	int xx[8] = { -1,  0, +1, -1, +1, -1, 0, 1 };

	for (int i = 0; i < 8; i++)
	{
		if (hasWord(y + yy[i], x + xx[i], n + 1))
			return ret = 1;
	}

	return ret = 0;
}

bool CheckHasWord()
{
	bool bHasWord = false;
	for (int y = 0; y < 5; y++)
	for (int x = 0; x < 5; x++)
		if (hasWord(y, x, 0))
			return true;

	return false;
}


int main()
{
#if 0 
	ifstream fin("input.txt");
	istream& in = fin;
#else
	istream& in = cin;
#endif

	int C;
	in >> C;

	while (C--)
	{
		for (int i = 0; i < 5; i++)
			in >> M[i];

		int N;
		in >> N;
		while (N--)
		{
			memset(&cache, -1, sizeof(cache));
			in >> w;
			cout << w << " " << (CheckHasWord() ? "YES" : "NO") << endl;
		}
	}

	return 0;
}

