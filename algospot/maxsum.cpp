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

	}

	return 0;
}
