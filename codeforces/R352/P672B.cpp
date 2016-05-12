#include <algorithm>
#include <vector>
#include <set>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	int A;
	cin >> A;

	if (A > 26)
	{
		cout << -1 << endl;
		return 0;
	}
	string B;
	cin >> B;

	set<int> K;
	for (int i = 0; i < B.size(); i++)
		K.insert(B[i]);

	cout << A - K.size() << endl;

	return 0;
}
