#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int main() {
	map<char, int> cnt;
	string str;
	cin >> str;
	for (auto s : str) {
		if (s >= 'a')
			s = (s + 'A' - 'a');
		if (65 <= s && s <= 90)
			cnt[s]++;
	}
	char m = 0;
	int c = 0, sz = 0;
	for (auto a : cnt) {
		if (sz < a.second) {
			m = a.first;
			c = 1;
			sz = a.second;
		} else if (sz == a.second) {
			c++;
		}
	}
	cout << (c > 1 ? '?' : m) << endl;
	return 0;
}