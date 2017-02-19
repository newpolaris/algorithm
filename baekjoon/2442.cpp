#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;

int main() {
#ifdef _DEBUG
#endif
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n-i-1; j++) cout << " ";
		for (int j = 0; j < 2*i+1; j++) cout << "*";
		cout << endl;
	}
	return 0;
}
