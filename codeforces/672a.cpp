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
	int i = 1;
	while (B.size() <= 1000)
		B += to_string(i++);

	cout << B[A-1] << endl;
	return 0;
}
