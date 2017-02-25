#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

#define all(x) (x).begin(), (x).end()
#define forn(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define sz(x) (int((x).size()))

using namespace std;

typedef unsigned int uint;
int n, l;
vector<bool> k;

void erathosthenes() {
	k[0] = k[1] = false;
	for (uint i = 2; i*i <= n; i++) {
		if (!k[i]) continue;
		for (uint j = i*i; j <= n; j+= i)
			k[j] = false;
	}
}


int main() {
#ifdef _DEBUG
	freopen("776b0.in", "r", stdin);
#endif
	ios::sync_with_stdio(0);

	cin >> l;
	n = l + 2;
	k.assign(n, true);
	erathosthenes();

	cout << (l <= 2 ? 1 : 2) << endl;
	for (int i = 2; i <= l+1; i++)
		cout << (k[i] ? 1 : 2) << " ";
	cout << endl;

	return 0;
}
