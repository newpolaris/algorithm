#include <iostream>
#include <iomanip>
#include <stdio.h>

using namespace std;
int main() {
	ios::sync_with_stdio(0);
	int x;
	cin >> x;
	cout << [](int x) {
		if (x >= 90) return 'A';
		if (x >= 80) return 'B';
		if (x >= 70) return 'C';
		if (x >= 60) return 'D';
		return 'F';
	}(x) << endl;
	return 0;
}
