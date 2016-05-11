#include <string.h>
#include <algorithm>
#include <functional>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

vector<int> fence;

int maxBox(int s, int e)
{
	if (s+1 == e)
		return fence[s];

	if (s >= e)
		return 0;

	int mid = (s+e)/2;
	int l = mid;
	int r = mid+1;
	int Box = 0;

	while (true)
	{
		if (l < s && r > e - 1)
			break;

		int target = 0;

		if (l >= s)
			target = fence[l];
		if (r <= e - 1)
			target = max(target, fence[r]);

		while (l >= s && target <= fence[l])
			l--;

		while (r <= e - 1 && target <= fence[r])
			r++;

		int lc = (mid - l);
		int rc = (r - mid - 1);

		Box = max(Box, (lc + rc)*target);
	}

	Box = max(Box, maxBox(s, (s+e)/2));
	Box = max(Box, maxBox((s+e)/2+1, e));

	return Box;
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

		cout << maxBox(0, N) << endl;
	}
	
	return 0;
}

