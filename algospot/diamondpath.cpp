#include <iostream>
#include <vector>
#include <string.h>

int cache[201][101];
int diamond[201][101];
int N;

using namespace std;

int path(int r, int c)
{
	if (c < 0 || c >= N || r >= 2*N || diamond[r][c] == 0) return 0;
	int& ret = cache[r][c];
	if (ret != 0) return ret;

	ret = diamond[r][c];
	int cc = (r < N - 1) ? c : c - 1;
		ret += max(path(r+1, cc), path(r+1, cc+1));
	return ret;
}

int main()
{
#ifdef _DEBUG
	freopen("diamondpath.in", "r", stdin);
#endif

	int C;
	cin >> C;
	while (C--) {
		cin >> N;
		memset(diamond, 0, sizeof(diamond)); 
		for (int r = 0; r < 2*N-1; r++) {
			int k = r >= N ? 2*N - 2 - r : r;
			for (int c = 0; c <= k; c++)
				cin >> diamond[r][c];
		}
		memset(cache, 0, sizeof(cache));
		cout << path(0, 0) << endl;
	}
	return 0;
}
