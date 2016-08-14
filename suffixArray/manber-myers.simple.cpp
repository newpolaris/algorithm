// 맨버-마이어스
// Manber-Myers, suffix array : A new method for on-line string searches

#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>

using namespace std;

// O(nlog^2(n)) s의 접미사 배열을 계산한다.
vector<int> getSuffixArray(const string& s) {
	int n = s.size();
	// group[i] = 접미사들을 첫 t 글자를 기준으로 정렬했을 때,
	// s[i:]가 들어가는 그룹 번호.
	// t = 1 일 때는 정렬할 것 없이 s[i:]의 첫 글자로 그룹 번호를
	// 정해 줘도 같은 효가가 있다.
	int t = 1;

	vector<int> group(n+1);
	group[n] = -1;
	for (int i = 0; i < n; i++) group[i] = s[i];

	vector<int> perm(n);
	for (int i = 0; i < n; i++) perm[i] = i;

	while (t < n) {
		// group[]은 첫 t글자를 기준으로 계산해 뒀다.
		// 첫 2*t 글자를 기준으로 perm을 다시 정렬한다.
		
		// 각 접미사들의 첫 t 글자를 기준으로 한 그룹 번호가 주어질 때,
		// 주어진 두 접미사를 첫 2*t 글자를 기준으로 비교한다.
		// group[]은 길이가 0인 접미사도 포함한다.
		auto compareUsing2T = [&](int a, int b) {
			// 첫 t 글자가 다르면 이들을 이용해 비교한다
			if (group[a] != group[b])
				return group[a] < group[b];
			// 아니라면 s[a+t:]와 s[b+t:]의 첫 t글자를 비교한다
			return group[a+t] < group[b+t];
		};

		sort(perm.begin(), perm.end(), compareUsing2T);

		// 2*t 글자가 n을 넘는다면 이제 접미사 배열 완성
		t *= 2;
		if (t > n) break;

		// 2t 글자를 기준으로 한 그룹 정보를 만든다.
		vector<int> newGroup(n+1);
		newGroup[perm[0]] = 0;
		newGroup[n] = -1;

		for (int i = 1; i < n; i++) {
			int nextGroup = compareUsing2T(perm[i-1], perm[i]);
			newGroup[perm[i]] = newGroup[perm[i-1]] + nextGroup;
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

// s의 서로 다른 부분 문자열의 수를 센다.
int countSubstrings(const string& s) {
	vector<int> a = getSuffixArray(s);
	int ret = 0;
	int n = s.size();
	for (int i = 0; i < a.size(); ++i) {
		int cp = 0;
		if (i > 0) cp = commonPrefix(s, a[i-1], a[i]);
		// a[i]의 (n-a[i]) 개의 접두사들 중에서 cp개는 중복이다.
		ret += s.size() - a[i] - cp;
	}
	return ret;
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
#else
	string s("alohomora");
	auto r = getSuffixArray(s);

	copy(begin(r), end(r), ostream_iterator<int>(cout, ", "));
#endif

	return 0;
}
