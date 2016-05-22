#include <iostream>
#include <assert.h>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <string.h>

using namespace std;

int H, W;

int Block[4][3][2] = {
	{ {0,0}, {1,0}, { 0,1} },
	{ {0,0}, {0,1}, {-1,1} },
	{ {0,0}, {0,1}, {+1,1} },
	{ {0,0}, {1,0}, {+1,1} },
};

bool set(vector<vector<int>>& M, int x, int y, int b, bool unset)
{
	auto bRet = true;
	for (int i = 0; i < 3; i++)
	{
		auto k = Block[b][i];

		int xx = x + k[0];
		int yy = y + k[1];
		if (xx < 0 || xx >= W || yy < 0 || yy >= H)
		{
			return false;
		}
		else
		{
			M[yy][xx] += (unset ? -1 : 1);
			if (M[yy][xx] > 1)
				bRet = false;
		}
	}
	return bRet;
}

int cover(vector<vector<int>>& M)
{
	int ex, ey;
	ex = ey = -1;
	for (int y = 0; y < H; y++)
	{
		for (int x = 0; x < W; x++)
			if (M[y][x] == 0)
			{
				ex = x;
				ey = y;
				break;
			}
		if (ex != -1)
			break;
	}
	if (ey == -1) 
		return 1;

	int ret = 0;
	for (int i = 0; i < 4; i++)
	{
		bool bSet = set(M, ex, ey, i, false);
		if (bSet)
			ret += cover(M);
		set(M, ex, ey, i, true);
	}

	return ret;
}

int main()
{
#if _DEBUG
	ifstream fin("boardcover.in");
	istream& in = fin;
#else
	istream& in = cin;
#endif

	int C;
	in >> C;

	while (C--)
	{
		in >> H >> W;

		auto InM = vector<string>(H);
		for (int y = 0; y < H; y++)
			in >> InM[y];

		vector<vector<int>> M(H, vector<int>(W));

		for (int y = 0; y < H; y++)
		for (int x = 0; x < W; x++)
			M[y][x] = InM[y][x] == '#' ? 1 : 0;

		cout << cover(M) << endl;
	}

	return 0;
}
