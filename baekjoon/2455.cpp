#include <iostream>
#include <cstdio>

using namespace std;

int main() {
	int n = 4; 
	int cnt = 0;
	int maxcnt = 0;
	while (n--) {
		int a, b;
		scanf("%d%d", &a, &b);
		cnt = cnt + b - a;
		maxcnt = max(cnt, maxcnt);
	}
	cout << maxcnt << endl;
	return 0;
}