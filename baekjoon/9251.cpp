#include <iostream>
#include <string.h>
#include <vector>

#define forn(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define fori(i, a, b) for (int i = (a), i##_end_ = (b); i > i##_end_; --i)

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("2294.in", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	int n, k;	
	cin >> k >> n;
    int cache[10001];
    memset(cache, -1, sizeof(cache));
}
