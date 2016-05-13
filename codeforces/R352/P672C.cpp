#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main()
{
#if _DEBUG
	ifstream fin("P672C.in");
	istream& in = fin;
#else
	cin.sync_with_stdio(0);
	istream& in = cin;
#endif

	int n, k;
	in >> n >> k;

	vector<int> A(n);
	for (auto& a : A)
		in >> a;

	ll hi; 
	ll lo; 
	hi = 2e9;
	lo = 1;
	while (lo < hi)
	{
		int mid = (lo + hi) / 2;
		if (mid == lo)
			break;
		ll sum = 0;
		for (int i = 0; i < n; i++)
			sum += max(mid - A[i], 0);
		if (sum <= k)
			lo = mid;
		else
			hi = mid;
	}

	ll t = k;
	for (int i = 0; i < n; i++)
	{
		t -= max(0LL, lo - A[i]);
		A[i] = max((ll)A[i], lo);
	}

	for (int i = 0; i < n; i++)
		if (A[i] == lo and t) {
			t--;
			A[i]++;
		}

	hi = 2e9;
	lo = 1;

	while (lo < hi)
	{
		int mid = (lo + hi) / 2;
		ll sum = 0;
		for (int i = 0; i < n; i++)
			sum += max(A[i] - mid, 0);
		if (sum <= k)
			hi = mid;
		else
			lo = mid + 1;
	}

	t = k;
	for (int i = 0; i < n; i++)
	{
		t -= max(0LL, A[i] - lo);
		A[i] = min((ll)A[i], lo);
	}

	for (int i = 0; i <= n; i++)
		if (A[i] == lo and t) {
			t--;
			A[i]--;
		}

	auto pr = minmax_element(A.begin(), A.end());
	cout << (*pr.second - *pr.first) << endl;

	return 0;
}
