// https://www.topcoder.com/community/data-science/data-science-tutorials/binary-search/
// Lower bound and Upper bound
/*
 * Robin Hood 구하는 알고리즘
 * 빼면 0 이하가 골치. 더하고 빼는 아이디어
 * 바이너리 serach 의 실제 적용 
 */
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
	ifstream fin("P671b.in");
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

	// Binary serach로 중간값을 구한다.
	ll hi = 2e9; // 임의의 큰 값
	ll lo = 1;
	while (lo < hi)
	{
		int mid = (lo + hi) / 2;
		// + 1 주의. lo = mid 하면 짤리는 현상
		// 대비해서 무조건 + 1 or mid = lo + (hi-lo+1)/2
		if (mid == lo) 
			mid++;

		// 그 중간값을 K로 했을 때 주어진 k 보다 
		// 작은 구간을 택한다 (조건을 만족하는 최대 값 구하기)
		ll sum = 0;
		for (int i = 0; i < n; i++)
			sum += max(mid - A[i], 0);
		if (sum <= k)
			lo = mid;
		else
			hi = mid - 1; // (크다면 mid 까지 포기)
	}

	ll t = k;
	for (int i = 0; i < n; i++)
	{
		t -= max(0LL, lo - A[i]);
		A[i] = max((ll)A[i], lo);
	}

	// 남은 것을lo 에 임의 배치. sort 안하는 방식일 상관 없음
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
			lo = mid + 1; // (초건 만족하는 최소값 구하기)
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
