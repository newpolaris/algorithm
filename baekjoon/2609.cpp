#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
int main() {
#ifdef _DEBUG
#endif
	ios::sync_with_stdio(0);
	int a, b;
	cin >> a >> b;
	int k =gcd(a, b);
	cout << k << endl << ((a/k)*(b/k)*k) << endl;
	return 0;
}
