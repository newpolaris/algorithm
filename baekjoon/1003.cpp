#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string.h>

#define x first
#define y second

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	int T, N;

	cin >> T;
	int arr[50][2];
	memset(arr, 0, sizeof(arr));
	arr[0][0] = 1;
	arr[1][1] = 1;
	for (int i = 2; i < 49; i++) {
		arr[i][0] = arr[i-1][0] + arr[i-2][0];
		arr[i][1] = arr[i-1][1] + arr[i-2][1];
	}
	while (T--) {
		cin >> N;
		cout << arr[N][0] << " " << arr[N][1] << endl;
	}
	return 0;
}
