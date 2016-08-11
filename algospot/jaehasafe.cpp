#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> getPartialMatch(const string& a)
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

// N : pattern
int kmpSearchFirst(const string& H, const string& N)
{
	auto pi = getPartialMatch(N);

	int z = H.size(), l = N.size();
	int matched = 0;
	for (int i = 0; i < z; i++)
	{
		while (matched > 0 && H[i] != N[matched])
			matched = pi[matched-1];
		if (H[i] == N[matched]) {
			matched++;
			// 가장 가까운 것을 반환
			if (matched == l)
				return i - l + 1;
		}
	}
	return -1;
}

int shifts(const string& original, const string& target) {
	return kmpSearchFirst(original + original, target);
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
		cin >> n;
		vector<string> str(n+1);
		for (auto& k : str)
			cin >> k;

		int count = 0;
		for (int i = 0; i < n; i++) {
			if (i % 2)
				count += shifts(str[i], str[i+1]);
			else 
				count += shifts(str[i+1], str[i]);
		}

		cout << count << endl;
	}

	return 0;
}

