#include <iostream>
#include <numeric>
#include <algorithm>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
#if _DEBUG
	ifstream fin("maxsum.in");
	istream& in = fin;
#else
	istream& in = cin;
#endif

	int C;
	in >> C;

	while (C--)
	{
		int N;
		in >> N;
		vector<int> L(N);
		for (auto& l : L)
			in >> l;

		int maxsum = 0;

		auto is = L.begin();
		while (is != L.end())
		{
			auto ie = find_if(is, L.end(), [](int k) { return k < 0; });
			maxsum = max(maxsum, accumulate(is, ie, 0));
			is = ie;
			if (is != L.end())
				is++;
		}
		cout << maxsum << endl;
	}

	return 0;
}
