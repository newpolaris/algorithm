#include <algorithm>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
#if _DEBUG
	ifstream fin("lis.in");
	istream& in = fin;
#else
	istream& in = cin;
#endif

	int C, N;

	in >> C;

	while (C--)
	{
		in >> N;
		vector<int> L(N);
		for (auto& n : L)
			in >> n;

		const int Max = 987654321;
		vector<int> cache (N, Max);
		for (auto& e : L)
			*lower_bound(cache.begin(), cache.end(), e) = e;

		auto it = lower_bound(cache.begin(), cache.end(), Max);
		cout << distance(cache.begin(), it) << endl;
	}

	return 0;
}
