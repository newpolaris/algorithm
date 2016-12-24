#include <iostream>
#include <algorithm>

using namespace std;

const int L = 10000000;
int factors[L+1];

int main() {
#ifdef _DEBUG
	freopen("pass486.in", "r", stdin);
#endif
	for (int div = 1; div <= L; div++)
		for (int multi = div; multi <= L; multi += div)
			factors[multi] += 1;
	int c, a, b, n;
	cin >> c;
	while (c--) {
		cin >> n >> a >> b;
		cout << count_if(&factors[a], &factors[b+1], [&](int i) { return i == n; }) << endl;
	}
	return 0;
}
