#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

typedef long long ll;

string N;
ll rep(string k, ll base, ll i) {
	int sp = max((int)(k.size() - N.size()), 0);
	string nk = k.substr(sp, k.size() - sp);
	string r = k.substr(0, sp);
	while ((N.size() <= nk.size() && N <= nk) || (nk.size() > 0 && nk[0] == '0' && stoll(nk) != 0)) {
		sp += 1;
		nk = k.substr(sp, k.size() - sp);
		r = k.substr(0, sp);
	}
	if (nk == "") return 0;
	return pow(base, i)*stoll(nk) + rep(r, base, i+1);
}

int main() {
#ifdef _DEBUG
	freopen("758d.in", "r", stdin);
#endif
	ll n, k;
	cin >> n >> k;
	
	N = to_string(n);
	cout << rep(to_string(k), n, 0) << endl;
}
