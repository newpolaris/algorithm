#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> getPartialMatch(string& a)
{
	int n = a.size();
	vector<int> pi(n, 0);

	int matched = 0;
	for (int i = 1; i < n; i++)
	{
		while (matched > 0 && a[i] != a[matched])
			matched = pi[matched-1];
		if (a[i] == a[matched]) matched++;
		pi[i] = matched;
	}
	return pi;
}

int main()
{
#ifdef _DEBUG
	freopen("jaehasafe.in", "r", stdin);
#endif

	int c, n;
	cin >> c;
	while (c--)
	{
		string a;

		cin >> n;
		cin >> a;
		vector<string> str(n);
		for (auto& k : str)
			cin >> k;

		auto pi = getPartialMatch(a);

		int z = a.size();
		vector<int> idx;
		for (int l = 0; l < str.size(); l++)
		{
			string& s = str[l];
			int matched = 0;
			for (int i = 0; i < 2*z; i++)
			{
				while (matched > 0 && a[matched] != s[i%z])
					matched = pi[matched-1];
				if (a[matched] == s[i%z]) {
					matched++;
					// 진행이 끝까지 된 것을 반환한다.
					if (matched == z) {
						idx.push_back((i - z + 1)%z);
						break;
					}
				}
			}
		}
		int count = idx[0];
		for (int i = 1; i < idx.size(); i++) {
			auto t = idx[i] - idx[i-1];
			count += (((i % 2) ? -t : t) + z) % z;
		}
		cout << count << endl;
	}

	return 0;
}

