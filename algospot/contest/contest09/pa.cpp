#include <iostream>
#include <vector>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("pa.in", "r", stdin);
#endif

	int c;
	cin >> c;
	while (c--) {
		vector<int> a(4, 0), b(4, 0);
		for (auto& i : a) cin >> i;
		for (auto& i : b) cin >> i;
		for (int i = 0; i < 4; i++)
			a[i] += b[i];
		for (int i = 0; i <= 1; i++)
			if (a[i] < 1) a[i] = 1;
		for (int i = 2; i <= 2; i++)
			if (a[i] < 0) a[i] = 0;
		cout << (a[0] * 1 + 5 * a[1] + 2 * a[2] + 2 * a[3]) << endl;
	}

	return 0;
}
