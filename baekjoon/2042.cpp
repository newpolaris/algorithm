#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;

// 0 <= L, R <= A.size()
// 0 <= S, E <= L.size()

ll init(const vector<ll>& A, vector<ll>& T, int N, int L, int R)
{
	if (L == R)
		return T[N] = A[L];
	int M = (L + R) / 2;
	return T[N] = init(A, T, N * 2, L, M) + init(A, T, N * 2 + 1, M+1, R);
}


void update(vector<ll>& T, int N, int S, int E, int I, ll Diff)
{
	if (S > I || E < I) return;

	T[N] += Diff;

	if (S != E)
	{
		int M = (S + E) / 2;
		update(T, N * 2, S, M, I, Diff);
		update(T, N * 2 + 1, M + 1, E, I, Diff);
	}
}
ll sum(const vector<ll>& T, int N, int S, int E, int L, int R)
{
	if (L > E || R < S) return 0LL;

	if (L <= S && E <= R)
		return T[N];

	int M = (S + E)/2;

	return sum(T, N * 2, S, M, L, R) + sum(T, N * 2 + 1, M + 1, E, L, R);
}


int main()
{
#ifdef _DEBUG
	fstream fin("2042.in");
	istream& in = fin;
#else
	istream& in = cin;
#endif

	int n, m, k;

	in >> n >> m >> k;
	vector<ll> A(n);
	for (auto& a : A)
		in >> a;

	int h = ceil(log2(n));
	int size = 1 << (h+1);

	vector<ll> T(size);

	init(A, T, 1, 0, n - 1);

	m += k;
	while (m--) {
		int t1, t2;
		ll t3;
		in >> t1 >> t2;
		in >> t3;
		if (t1 == 1) {
			t2-=1;
			long long diff = t3-A[t2];
			A[t2] = t3;
			update(T, 1, 0, n-1, t2, diff);
		} else if (t1 == 2) {
			printf("%lld\n",sum(T, 1, 0, n-1, t2-1, t3-1));
		}
	}
	return 0;
}

