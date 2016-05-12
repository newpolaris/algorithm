#include <algorithm>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	int A;
	cin >> A;

	string B;
	for (int i = 1; i <= 1000; i++)
	{
		B += to_string(i);
		if (B.size() > 1000)
			break;
	}

	cout << B[A-1] << endl;
	return 0;
}
