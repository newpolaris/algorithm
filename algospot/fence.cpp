#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

vector<int> fence;

int solve(int left, int right)
{
	// 1개 블록 처리
	if (left >= right)
		return fence[left];

	//2개 이상의 블록을 처리
	int mid = (left+right)/2;
	int lo = mid, hi = mid+1;

	// 가운데를 기준으로 나눠 처리
	int ret = max(solve(left, lo), solve(hi, right));

	while (lo >= left || hi <= right)
	{
		// target max를 구하자
		int target = 0;
		if (lo >= left)
			target = fence[lo];
		if (hi <= right)
			target = max(target, fence[hi]);

		// 보다 큰쪽으로 확장을 시도
		while (lo >= left && target <= fence[lo])
			lo--;

		while (hi <= right && target <= fence[hi])
			hi++;

		ret = max(ret, (hi - lo - 1)*target);
	}

	return ret;
}

int main()
{
#if _DEBUG
	freopen("fence.in", "r", stdin);
#endif

	int C, N;
	cin >> C;

	while (C--)
	{
		cin >> N;
		fence.resize(N);
		for (auto& f : fence)
			cin >> f;

		cout << solve(0, N-1) << endl;
	}
	return 0;
}

