#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <vector>

using namespace std;

int house[1000][3];
int c[1000][3];

int main() {
#ifdef _DEBUG
	freopen("1149.in", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	int n;
	scanf("%d",&n);
	for (int i = 0; i < n; i++) for (int j = 0; j < 3; j++) scanf("%d", &house[i][j]);
	for (int i = 0; i < 3; i++) c[0][i] = house[0][i];
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < 3; j++)
			c[i][j] = 1e9;

		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				if (j == k) continue;
				c[i][j] = min(house[i][j] + c[i-1][k], c[i][j]);
			}
		}
	}
	int ret = int(1e9);
	for (int i = 0; i < 3; i++) ret = min(ret, c[n-1][i]);
	cout << ret << endl;

	return 0;
}
