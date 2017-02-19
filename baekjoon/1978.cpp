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
	
	vector<bool> arr(1001, true);
	arr[0] = false;
	arr[1] = false;

	// erathosthenes()
	for (int i = 2; i*i <= arr.size(); i++) {
		for (int k = i*i; k <= arr.size(); k += i) {
			arr[k] = false;
		}
	}
	int n, a, c = 0;
	cin >> n;
	while (n--) {
		cin >> a;
		if (arr[a]) c++;
	}
	cout << c << endl;
	return 0;
}
