#include <iostream>
#include <cmath>
#include <strstream>
#include <random>

using namespace std;

typedef long long ll;

int binary_search(ll N, ll M)
{
	ll Z, low, high, mid;
	Z = (M * 100)/N;
	auto p = [&](ll mid) { return (M+mid)*100/(N+mid) > Z; };
	low = 1;
	high = 2000000000;
	while (low < high)
	{
		mid = (low + high)/2;
		if (p(mid) == true) high = mid;
		else low = mid + 1;
	}
	if (p(low) == false) low = -1;
	return low;
}

int floating_math(ll N, ll M)
{
	ll need;
	auto rate = (double)M/N;
	rate += 0.01;
	rate *= 100.0;
	ll r = (ll)rate;
	if (r >= 100)
		need = -1;
	else {
		auto fNeed = (double)(r * N - 100 * M) / (100.0 - r);
		need = (ll)ceil(fNeed);
	}
	return need;
}

int main()
{
	random_device rd;
	mt19937 gen(rd());
	int T = 1000000;
	int K = 100;
	uniform_int_distribution<> GN(1000000, 1000000000);
	while (T--)
	{
		ll N = GN(gen);
		uniform_int_distribution<> GM(1000, N);
		for (int k = 0; k < K; k++)
		{
			ll M = GM(gen);
			auto r1 = floating_math(N, M);
			auto r2 = binary_search(N, M);
			if (r1 != r2)
			{
				cout << N << " " << M << " " << r1 << " " << r2 << endl;
			}
		}
	}
	return 0;
}

