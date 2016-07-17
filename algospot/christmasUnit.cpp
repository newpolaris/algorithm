#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pii;

int N=5, K=1;

pii greedy(vi in)
{
	int r = 0;
	for (auto& i : in)
		i = r = (i + r) % K;

	vector<int> L(K, 0);
	L[0]++;
	for (auto& i : in)
		L[i]++;
	long long A = 0;
	for (long long l : L)
		if (l >= 2)
			A = (A + l*(l-1)/2) % 20091101;

	vector<vector<int>> H(K);
	H[0].push_back(0);
	for (int i = 0; i < in.size(); i++)
		H[in[i]].push_back(i+1);
	vector<pair<int,int>> G;
	for (auto& h : H)
		if (h.size() > 1)
			for (int i = 0 ; i+1 < h.size(); i++)
				G.push_back({h[i+1], h[i]});

	sort(begin(G), end(G));
	int last = -1, B = 0;
	for (auto& g : G)
	{
		if (g.second >= last)
		{
			last = g.first;
			B++;
		}
	}
	return {A,B};
}

int waysToBuy(vi& psum)
{
	const int MOD = 20091101;
	int ret = 0;
	vector<long long> count(K, 0);
	for (int i = 0; i < psum.size(); i++)
		count[psum[i]]++;
	for (int i = 0; i < K; ++i)
		if (count[i] >= 2)
			ret = (ret + (count[i]*(count[i]-1)/2)) % MOD;
	return ret;
}

int maxBuys(vi psum)
{
	vector<int> ret(psum.size(), 0);
	vector<int> prev(K, -1);
	for (int i = 0; i < psum.size(); i++)
	{
		if (i > 0)
			ret[i] = ret[i-1];
		else
			ret[i] = 0;

		int loc = prev[psum[i]];
		if (loc != -1)
			ret[i] = max(ret[i], ret[loc] + 1);
		prev[psum[i]] = i;
	}
	return ret.back();
}

pii dynamic(vi in)
{
	vi ii(in.size()+1, 0);
	int r = 0;
	for (int i = 0; i < in.size(); i++)
		ii[i+1] = r = (in[i] + r) % K;
	auto A = waysToBuy(ii);
	auto B = maxBuys(ii);
	return {A,B};
}

int main()
{
#if _DEBUG
//	freopen("christmas.out", "w", stdout);
#endif
	int T = 9;

	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> GN(1, 2);

	while (T--)
	{
#if 1
		vi in(N);
		for (auto& i : in) i = GN(gen);
#else
		// vi in = { 2, 1, 2, 1, 2, 5 };
		// vi in = { 1, 5, 4, 3, 2, 3 };
		vi in = { 1, 3, 9, 7, 9, 11 };
#endif
		auto a = greedy(in);
		auto b = dynamic(in);

		if (a == b) continue;

		for (auto i = 0u; i < in.size(); i++)
			cout << in[i] << " \n"[i+1 == in.size()];
		cout << a.first << " " << a.second << endl;
		cout << b.first << " " << b.second << endl;
	}

	return 0;
}
