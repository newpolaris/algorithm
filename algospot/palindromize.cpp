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

		int matched = 0, begin = 0;
		int n = a.size();
		while (begin < n)
		{
			if (matched < n && a[begin + matched] == ra[matched])
			{
				matched++;
				if (begin + matched == n)
					break;
			}
			else
			{
				if (matched == 0)
					begin++;
				else
				{
					begin += matched - pi[matched-1];
					matched = pi[matched-1];
				}
			}
		}
		cout << n + begin << endl;
	}

	return 0;
}

