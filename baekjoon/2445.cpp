#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	for (int i = 1; i < 2*n; i++) {
		auto k = min(i, 2*n - i);
		for (int j = 0; j < k; j++) cout << "*";
		for (int j = 0; j < 2*(n-k); j++) cout << " ";	
		for (int j = 0; j < k; j++) cout << "*";
		cout << endl;
	}
	return 0;
}