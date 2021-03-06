#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int N, K, M, L, INF = 987654321;
int cache[1<<12][11];
int classes[11];
int prerequisite[12];
vvi Require, Semester;

int bitcount(int n)
{
	int count = 0;
	while (n) {
		++count;
		n = (n - 1) & n;
	}
	return count;
}

bool nextComb(vi& v, int n, int r)
{
	if (v.size() <= 0) 
		return false;
	int i = r;
	while (v[i-1] == n - r + i)
		i--;
	i--;
	if (i >= r || i < 0)
		return false;
	v[i] += 1;
	for (int j = i + 1; j < r; j++)
		v[j] = v[j - 1] + 1;
	return true;
}

int graduate(int taken, int semester)
{
	if (bitcount(taken) >= K) return 0;
	if (semester >= M) return INF;

	int& ret = cache[taken][semester];
	if (ret > 0) return ret;
	ret = INF;

	int canTake = (classes[semester] & ~taken);
	for (int i = 0; i < N; i++)
		if ((canTake & (1 << i)) && 
				(taken &  prerequisite[i]) != prerequisite[i])
			canTake &= ~(1 << i);
	for (int take = canTake; take > 0; take = ((take - 1) & canTake)) {
		if (bitcount(take) > L) continue;
		ret = min(ret, graduate(taken | take, semester + 1) + 1);
	}
	ret = min(ret, graduate(taken, semester + 1));
	return ret;
}

void read(int* t, int k)
{
	for (int i = 0; i < k; i++)
	{
		int a, b, c = 0;
		cin >> a;
		for (int j = 0; j < a; j++)
		{
			cin >> b;
			c |= (1 << b);
		}
		t[i] = c;
	}
}

int main()
{
#ifdef _DEBUG
	freopen("graduation.in", "r", stdin);
#endif

	int C;
	cin >> C;
	while (C--)
	{
		cin >> N >> K >> M >> L;	

		memset(cache, -1, sizeof(cache));
		memset(classes, 0, sizeof(classes));
		memset(prerequisite, 0, sizeof(prerequisite));

		read(prerequisite, N);
		read(classes, M);

		int k = graduate(0, 0);
		if (k <= K)
			cout << k << endl;
		else
			cout << "IMPOSSIBLE" << endl;
	}

	return 0;
}

