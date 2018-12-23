#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
#ifdef _DEBUG
	// freopen("863a.in", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	std::string k;
	cin >> k;
	int j = 0;
	bool success = false;
	int i = k.size() - 1;
	for (; i >= 0; i--) 
		if (k[i] != '0') 
			break;
	for (; i >= 0; i--) 
	{
		if (i == j) {
			success = true;
			break;
		}
		if (i == j+1) 
		{
			success = k[i] == k[j];
			break;
		}
		if (k[i] != k[j]) 
			break;
		j++;
	}
	if (success)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

	return 0;
}
