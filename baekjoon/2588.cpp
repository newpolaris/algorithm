#include <iostream>

#define all(x) (x).begin(), (x).end()

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	int a, b;
	cin >> a >> b;
	int t = b;
	while (t) {
		cout << a * (t % 10) << endl;
		t /= 10;
	}
	cout << a*b << endl;
	
	return 0;
}
