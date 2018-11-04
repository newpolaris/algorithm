#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <map>
#include <stack>

#define forn(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define fori(i, a, b) for (int i = (a), i##_end_ = (b); i > i##_end_; --i)
#define x first
#define y second 
#define all(x) (x).begin(), (x).end()

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	int n, a;
	cin >> n;
	string command;
	stack<int> st;
	while (n--) {
		cin >> command;
		if (command == "push") {
			cin >> a;
			st.push(a);
		} else if (command == "top") {
			int t = -1;
			if (!st.empty())
				t = st.top();
			cout << t << endl;
		} else if (command == "size") {
			cout << st.size() << endl;
		} else if (command == "empty") {
			cout << st.empty() << endl;
		} else if (command == "pop") {
			int t = -1;
			if (!st.empty()) {
				t = st.top();
				st.pop();
			}
			cout << t << endl;
		}
	}
	return 0;
}
