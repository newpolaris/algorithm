#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
#ifdef _DEBUG
	freopen("722b.in", "r", stdin);
#endif

	int n;
	cin >> n;
	vector<int> list(n);
	for (auto &l : list)
		cin >> l;
	string vowel("aeiouy");

	string word;
	getline(cin, word);
	for (int i = 0; i < n; i++) {
		getline(cin, word);
		int cnt = 0;
		for (auto &c : vowel) {
			cnt += count(word.begin(), word.end(), c);
		}
		if (list[i] != cnt) {
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;

	return 0;
}
