#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <vector>
#include <string.h>

using namespace std;

/* 
 * 100000
 * 100001
 * 100010
 * 100100
 * 100101
 * 101000
 * 101001
 * 101010
 */

int main() {
#ifdef _DEBUG
#endif
	ios::sync_with_stdio(0);
	long long arr[100][2];
	memset(arr, 0, sizeof(arr));
	arr[1][1] = 1;
	int n;
	cin >> n;
	for (int i = 2; i <= n; i++) {
		// 0 더할 수 있는 경우
		arr[i][0] = arr[i-1][0] + arr[i-1][1];
		// 1 을 더할 수 있는 경우
		arr[i][1] = arr[i-1][0];
	}
	cout << (arr[n][0]+arr[n][1]) << endl;

	return 0;
}
