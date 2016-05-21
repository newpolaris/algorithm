#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <string.h>
#include <algorithm>

using namespace std;

int main()
{
	int a, b, c;

	cin >> a >> b >> c;

	if (c == 0)
	{
		cout << ((a == b) ? "YES" : "NO") << endl;
		return 0;
	}

	cout << ((b - a) / c >= 0 && ((b - a) % c) == 0 ? "YES" : "NO") << endl;

	return 0;
}
