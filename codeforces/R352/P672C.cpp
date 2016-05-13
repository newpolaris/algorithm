#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

int n, k;
long long sum = 0;

int main()
{
	cin.sync_with_stdio(0);
	cin >> n >> k;
	vector<int> A(n);
	for (auto& a : A)
		cin >> a;
	sort(A.begin(), A.end());
	int mx = A[n - 1], mn = A[0], kk = k;
	for (int i = n - 2; i >= 0; --i)
	{
		if (A[i] >= mx) 
			continue;
		int e = n - i - 1;
		int c = min(mx - A[i], kk / e);
		mx -= c;
		kk -= c * e;
	}
	kk = k;
	for (int i = 1; i < n; i++)
	{
		if (A[i] <= mn) 
			continue;
		int c = min(A[i] - mn, kk / i);
		mn += c;
		kk -= c * i;
	}
	for (int i = 0; i < A.size(); i++)
		sum += A[i];
	cout << max(sum % n ? 1 : 0, mx - mn) << endl;
}
