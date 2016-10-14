#include <iostream>
#include <string.h>

typedef long long ll;

ll a[100001], b[100001];
ll t;

using namespace std; 

int main() {
#ifdef _DEBUG
	freopen("712a.in", "r", stdin);
#endif
	int n;
	cin >> n;
	for (int i = n-1; i >= 0; i--)
		cin >> b[i];

	t = 0;
	for (int i = 0; i < n; i++) {
		a[i] = b[i] + t;
		t = a[i] - t;
	}

	for (int i = n - 1; i >= 0; i--) {
		cout << a[i] << " \n"[i == 0];
	}
	return 0;
}
