#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

int main()
{
#if _DEBUG
	ifstream fin("P672C.in");
	istream& in = fin;
#else
	istream& in = cin;
#endif

	int n, k;
	in >> n >> k;

	vector<int> A(n);
	for (auto& a : A)
		in >> a;

	sort(A.begin(), A.end());

	int mx = A[n - 1];
	int mn = A[0];
	int kk = k;
	for (int i = n - 2; i >= 0; --i)
	{
		if (A[i] >= mx) // 중간의 값은 넘버 처리를 위해 필요 
			continue;
		int e = n - i - 1;
		int c = min(mx - A[i], kk / e);
		mx -= c;
		kk -= c * e;
	}

	int ko = k;
	for (int j = 1; j < n; j++)
	{
		if (A[j] <= mn) // 중간의 값은 넘버 처리를 위해 필요 
			continue;
		int c = min(A[j] - mn, ko / j);
		mn += c;
		ko -= c * j;
	}

	// int type 이라 accumulator를 사용하면 넘친다
	typedef long long ll;
	ll sum = 0;
	for (int i = 0; i < A.size(); i++)
		sum += A[i];
	
	cout << max(sum % n ? 1 : 0, mx - mn) << endl;

	return 0;
}
