#include <iostream>
#include <iomanip>
#include <stdio.h>

using namespace std;
int main() {
	ios::sync_with_stdio(0);
	int a, b, c;
	cin >> a >> b >> c;
	cout << ((a+b)%c) << endl;
	cout << ((a+b)%c) << endl;
	cout << ((a*b)%c) << endl;
	cout << ((a*b)%c) << endl;
	return 0;
}
