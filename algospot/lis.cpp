#include <algorithm>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

vector<int> L, cache;

const int Max = 987654321;

int FindLisLength()
{
	for (int i = 0; i < L.size(); i++)
	{
		auto it = lower_bound(cache.begin(), cache.end(), L[i]);
		*it = L[i];
	}
	
	auto it = lower_bound(cache.begin(), cache.end(), Max);
	return distance(cache.begin(), it);
}

int main()
{
#if _DEBUG
	ifstream fin("lis.in");
	istream& in = fin;
#else
	istream& in = cin;
#endif

	int C, N, K;

	in >> C;

	while (C--)
	{
		in >> N >> K;
		L.resize(N);
		for (auto& n : L)
			in >> n;

		cache = vector<int>(N, Max);
		cout << FindLisLength() << endl;
	}

	return 0;
}
