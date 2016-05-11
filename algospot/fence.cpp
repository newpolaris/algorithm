#include <algorithm>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

vector<int> fence;

int solve(int left, int right)
{
	if (left >= right)
		return fence[left];

	int mid = (left+right)/2;
	int lo = mid, hi = mid+1;
	int ret = max(solve(left, lo), solve(hi, right));

	while (lo >= left || hi <= right)
	{
		int target = 0;
		if (lo >= left)
			target = fence[lo];
		if (hi <= right)
			target = max(target, fence[hi]);

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
	ifstream fin("fence.in");
	istream& in = fin;
#else
	istream& in = cin;
#endif

	int C, N;
	in >> C;

	while (C--)
	{
		in >> N;
		fence = vector<int>(N);
		for (auto& f : fence)
			in >> f;

		cout << solve(0, N-1) << endl;
	}
	
	return 0;
}

