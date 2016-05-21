/*
 * Robin Hood 구하는 알고리즘
 * 빼면 0 이하가 골치. 더하고 빼는 아이디어
 * 바이너리 serach 의 실제 적용 
 * (+1, -1 에 주의 특히 뺄때(안하면 뺄때 무한 루프))
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
	ifstream fin("P671B.in");
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
		if (mid == lo) // + 1 주의
			mid++;

		// 그 중간값을 K로 했을 때 주어진 k 보다 
		// 작은지 큰지에 따라 방향 결정
		ll sum = 0;
		for (int i = 0; i < n; i++)
			sum += max(mid - A[i], 0);
		if (sum <= k)
			lo = mid;
		else
			hi = mid - 1; // -1 주의
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
			lo = mid + 1; // (안하면 무한루프)
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
