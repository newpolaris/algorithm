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
	freopen("palindromize.in", "r", stdin);
#endif

	int c;
	cin >> c;
	while (c--)
	{
		string a;
		cin >> a;

		string ra(a.rbegin(), a.rend());
		auto pi = getPartialMatch(ra);

		int n = a.size();
		int matched = 0, i;
		for (int i = 0; i < n; i++)
		{
			while (matched > 0 && a[i] != ra[matched])
				matched = pi[matched-1];
			if (a[i] == ra[matched]) {
				matched++;
				// 진행이 끝까지 된 것을 반환한다.
				if (i - 1 == n)
					break;
			}
		}
		cout << n*2 - matched << endl;
	}

	return 0;
}

