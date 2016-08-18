// iddaga's solustion 347ms
#include <stdio.h>
#include <memory.h>
#include <map>

#define ML 4096
#define ll long long
#define MOD 10000000000013LL

using namespace std;

int n, k;
char d[ML];
map<ll,int> c;

bool help(int m) {
    int i, j;
	ll t, v;

	t = 1; 
	for (i = 0; i < m; i++) 
		t = t*26%MOD;

	c.clear();
	v = 0;
	for (i = 0; i < n; i++) {
		v = (v*26 + d[i]-'a')%MOD;
		if (i-m >= 0) {
			v -= t*(d[i-m]-'a')%MOD;
			if (v < 0) v += MOD;
		}
		if (i+1 >= m) {
			if (++c[v] == k) return 1;
		}
	}
	return 0;
}

int main()
{
	int t, T, s, e, m;

	scanf("%d",&T);
	for (t = 0; t < T; t++) {
		scanf("%d%s", &k, d);
		for (n = 0; d[n]; n++);
		for (s = 1, e = n; s <= e;) {
			m = (s+e)/2;
			if (help(m)) s = m+1;
			else e = m-1;
		}
		printf("%d\n",s-1);
	}
	return 0;
}
