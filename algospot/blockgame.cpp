#include <iostream>
#include <vector>
#include <bitset>
#include <string>
#include <string.h>

using namespace std;

int N = 5;
const int L = 6;

char cache[1<<25];
const vector<char> Xpos[] = { {0, 0, 1}, {0, 1, 1}, {0, 1, 1}, {0, 0, 1}, {0, 0}, {0, 1} };
const vector<char> Ypos[] = { {0, 1, 1}, {0, 0,-1}, {0, 0, 1}, {0, 1, 0}, {0, 1}, {0, 0} };

bool set(int& bs, int x, int y, int k, bool bSet)
{
	const vector<char> &xp = Xpos[k], &yp = Ypos[k];

	if (bSet)
	{
		for (int i = 0; i < xp.size(); i++)
		{
			int xx = x + xp[i], yy = y + yp[i];	
			if (xx >= N || xx < 0 || yy >= N || yy < 0)
				return false;
			int p = yy * N + xx;
			if (bs & (1 << p))
				return false;
		}
	}
	for (int i = 0; i < xp.size(); i++)
	{
		int xx = x + xp[i], yy = y + yp[i];	
		int p = yy * N + xx;
		if (bSet)
			bs |= (1 << p);
		else
			bs &= ~(1 << p);
	}
	return true;
}

bool set(int& bs, int x, int y, int k)
{
	return set(bs, x, y, k, true);
}

void reset(int& bs, int x, int y, int k)
{
	set(bs, x, y, k, false);
}

bool CanWin(int& bs)
{
	char& ret = cache[bs];
	if (ret != -1) return ret;

	ret = 0;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			for (int k = 0; k < L; k++) {
				if (!set(bs, x, y, k)) 
					continue;
				ret = !CanWin(bs);
				reset(bs, x, y, k);
				if (ret == 1)
					return ret;
			}
		}
	}

	return ret;
}

int main()
{
#ifdef _DEBUG
	freopen("blockgame.in", "r", stdin);
#endif
	memset(cache, -1, sizeof(cache));

	int C;
	cin >> C;
	while (C--)
	{
		int bs = 0;
		string s;
		for (int y = 0; y < N; y++) {
			cin >> s;
			for (int x = 0; x < N; x++) {
				if (s[x] == '#')
				{
					int p = y*N+x;
					bs |= (1 << p);
				}
			}
		}
		cout << (CanWin(bs) ? "WINNING" : "LOSING") << endl;
	}

	return 0;
}
