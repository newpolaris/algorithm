#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
#ifdef _DEBUG
	freopen("naming.in", "r", stdin);
#endif

	string a, b;
	cin >> a >> b;
	a += b;

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

	vector<int> len;
	int k = pi.size();
	while (k > 0) {
		len.push_back(k);
		k = pi[k-1];
	}

	int l = len.size();
	while (l--)
		cout << len[l] << " ";
	cout << endl;

	return 0;
}

