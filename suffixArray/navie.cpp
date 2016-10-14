// n^2logn solusion
#include <vector>
#include <string>
#include <iostream>

using namespace std;

vector<int> getSuffixArray(const string& s) { 
	vector<int> perm;
	for (int i = 0; i < s.size(); ++i) perm.push_back(i);
	sort(perm.begin(), perm.end(), [&](int a, int b) {
			return strcmp(s.c_str() + a, s.c_str() + b) < 0;
	});
	return perm;
}

int commonPrefix(const string& s, int a, int b) {
	int i = 0, n = s.size();
	for (i = 0; i < n - max(a, b); i++) 
		if (s[a+i] != s[b+i]) break;
	return i;
}

int longestFrequent(int k, const string& s) {
	vector<int> a = getSuffixArray(s);
	int ret = 0;
	for (int i = 0; i + k <= s.size(); ++i)
		ret = max(ret, commonPrefix(s, a[i], a[i + k - 1]));
	return ret;
}

int main()
{
	freopen("manber-myers.simple.in", "r", stdin);
	int c, k;
	string s;

	cin >> c;
	while (c--)
	{
		cin >> k;
		cin >> s;
		cout << longestFrequent(k, s) << endl;
	}
	return 0;
}
