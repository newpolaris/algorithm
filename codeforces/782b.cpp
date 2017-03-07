#include <iostream>
#include <queue>
#include <functional>
#include <algorithm>
#include <cstdio>
#include <cmath>

#define x first
#define y second
#define forn(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define pb push_back
#define mp make_pair

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("782b0.in", "r", stdin);
#endif
	int n, a, b;
	scanf("%d", &n);
	int x[n], v[n];
	forn(i, 0, n) scanf("%d", &x[i]);
	forn(i, 0, n) scanf("%d", &v[i]);

	double lo = *min_element(x, x+n);
	double hi = *max_element(x, x+n);
	auto f = [&](double p) {
		double s = 0;
		forn(i, 0, n) {
			double d = (double)x[i] - p;
			d = (d < 0) ? -d : d;
			s = max(s, d/double(v[i]));
		}
		return s;
	};

	for (int iter = 0; iter < 100; iter++) {
		double a = (2*lo + hi) / 3.0;
		double b = (lo + 2*hi) / 3.0;
		if (f(a) < f(b))
			hi = b;
		else
			lo = a;
	}
	double r = (lo+hi)/2.0;
	printf("%.14lf\n", f(r));
	return 0;
}
