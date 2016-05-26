#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <string.h>
#include <iostream>

using namespace std;

int main()
{
#if _DEBUG
	ifstream fin("restore.in");
	istream& in = fin;
#else
	istream& in = cin;
#endif

	int C, K;
	in >> C;

	while (C--)
	{
		in >> K;
		vector<string> L(K);
		for (auto& l : L)
			in >> l;

		sort(L.begin(), L.end(), 
				[](const string& a, const string& b) {
					return a.size() < b.size();
				});


	}

	return 0;
}

