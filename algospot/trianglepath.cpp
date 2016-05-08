/*
2
5
6
1  2
3  7  4
9  4  1  7
2  7  5  9  4
5
1 
2 4
8 16 8
32 64 32 64
128 256 128 256 128
*/

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string.h>

using namespace std;

int b[100][100];
int s[100][100];
int N;

int sum(int y, int x, int s)
{
	if (y >= N || x >= N)
		return 0;

	if (s[y][x] >= 0)
		return s[y][s];

	s[y][x] = b[y][x] + max(sum(y+1, x), sum(y+1, x+1));
	return s[y][x];
}

int main()
{
    istream& in = cin;
    ostream& ot = cout;

	int C;
	in >> C;

	while (C--)
	{
		in >> N;
		for (int y = 0 ; y < N; y++)
			for (int x = 0; x <= y; x++)
				in >> b[y][x];

		memset(&s, -1, 100*100);
		ot << sum(0, 0) << endl;
	}

	return 0;
}
