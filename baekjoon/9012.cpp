#include <iostream>
#include <string>

using namespace std;

int main() {
	int t;
	string str; 
	cin >> t;
	while (t--) {
		cin >> str;
		int st = 0;
		for (auto s : str) {
			if (s == '(') st++;
			if (s == ')') { 
				st--;
				if (st < 0) break;
			}
		}
		cout << (st == 0 ? "YES" : "NO") << endl;
	}
	return 0;
}
