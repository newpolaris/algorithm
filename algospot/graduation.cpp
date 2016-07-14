#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int N, K, M, L;
int cache[1<<12][11];
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
	for (int j = i + 1; j <= r; j++)
		v[j] = v[j - 1] + 1;
	return true;
}

int semester(int taken, int next)
{
	if (bitcount(taken) >= K)
		return 0;
	if (next >= M)
		return K + 1;

	int& ret = cache[taken][next];
	if (ret >= 0) return ret;
	ret = K + 1;

	auto& S = Semester[next];
	vi can;
	for (auto& s : S)
	{
		const auto& R = Require[s];
		auto bRegister = all_of(begin(R), end(R), 
				[&](int k) { return taken & (1 << k); });
		if (bRegister)
			can.push_back(s);
	}

	int n = can.size();
	int r = min(n, L);
	vi v(r);
	iota(begin(v), end(v), 1);
	do {
		int take = 0;
		for (auto& a : v)
			take |= (1 << can[a-1]);
		ret = min(ret, semester(taken + take, next + 1) + 1);
	}
	while (nextComb(v, n, r));
	ret = min(ret, semester(taken, next + 1));
	return ret;
}

void read(vvi& v, int k)
{
	v = vvi(N);
	for (auto& i : v)
	{
		cin >> k;
		i.resize(k);
		for (auto& t : i)
			cin >> t;
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

		read(Require, N);
		read(Semester, M);

		memset(cache, -1, sizeof(cache));

		int k = semester(0, 0);
		if (k <= K)
			cout << k << endl;
		else
			cout << "IMPOSSIBLE" << endl;
	}

	return 0;
}

