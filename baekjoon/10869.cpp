#include <iostream>
#include <iomanip>
#include <stdio.h>

using namespace std;
int main() {
	ios::sync_with_stdio(0);
	int x, y;
	cin >> x >> y;
	x--;
	int month[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	string days[] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };
	int d = 0;
	for (int i = 0; i < x; i++) {
		d = (d + month[i])%7;
	}
	cout << days[(d + y)%7] << endl;
	
	return 0;
}
