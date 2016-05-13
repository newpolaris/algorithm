#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

void doit(vector<int>& A, int k)
{
	sort(A.begin(), A.end());
	int mn = A[0];
	for (ll i = 1; i < A.size(); i++)
	{
		ll need = (A[i] - mn) * i;
		if (need <= k)
		{
			mn = A[i];
			k -= need;
		}
	}
	
	auto ub = upper_bound(A.begin(), A.end(), mn);
	auto dist = distance(A.begin(), ub);

	auto factor = k / dist;
	auto remainer = k % dist;
	
	fill(A.begin(), ub, mn + factor);
	for_each(A.begin(), A.begin() + remainer, [](int& a) { a++; });
}

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

	doit(A, k);
	for_each(A.begin(), A.end(), [](int& a) { a = -a; });
	doit(A, k);
	for_each(A.begin(), A.end(), [](int& a) { a = -a; });
	
	auto pr = minmax_element(A.begin(), A.end());

	cout << (*pr.second - *pr.first) << endl;

	return 0;
}
