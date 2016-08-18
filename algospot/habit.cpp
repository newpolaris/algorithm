// 맨버-마이어스
// Manber-Myers, suffix array : A new method for on-line string searches

#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>

using namespace std;

// s의 접미사 배열을 계산한다.
vector<int> getSuffixArray(const string& s) {
	int n = s.size();

	vector<int> group(n+1);
	group[n] = -1;

	int t = 1;
	for (int i = 0; i < n; i++) group[i] = s[i];

	vector<int> perm(n);
	for (int i = 0; i < n; i++) perm[i] = i;

	while (t < n)
	{
		auto compareUsing2T = [t, &group](int a, int b) {
			// 첫 t 글자가 다르면 이들을 이용해 비교한다
			if (group[a] != group[b])
				return group[a] < group[b];
			// 아니라면 s[a+t:]와 s[b+t:]의 첫 t글자를 비교한다
			return group[a+t] < group[b+t];
		};
		sort(perm.begin(), perm.end(), compareUsing2T);

		t *= 2;
		if (t > n) break;

		vector<int> newGroup(n+1);
		newGroup[perm[0]] = 0;
		newGroup[n] = -1;

		for (int i = 1; i < n; i++) {
			if (compareUsing2T(perm[i-1], perm[i]))
				newGroup[perm[i]] = newGroup[perm[i-1]] + 1;
			else
				newGroup[perm[i]] = newGroup[perm[i-1]];
		}
		group = newGroup;
	}
	return perm;
}

// s[a:]와 s[b:]의 공통 접두사의 최대 길이를 계산한다.
int commonPrefix(const string& s, int a, int b) {
	int i = 0, n = s.size();
	for (i = 0; i < n - max(a, b); i++) 
		if (s[a+i] != s[b+i]) break;
	return i;
}

// k번 이상 출현하는 s의 부분 문자열 중 최대 길이를 찾는다.
int longestFrequent(int k, const string& s) {
	vector<int> a = getSuffixArray(s);
	int ret = 0;
	for (int i = 0; i + k <= s.size(); ++i)
		ret = max(ret, commonPrefix(s, a[i], a[i + k - 1]));
	return ret;
}

int main()
{
#ifdef _DEBUG
	freopen("habit.in", "r", stdin);
#endif
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
