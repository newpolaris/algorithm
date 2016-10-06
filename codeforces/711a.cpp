#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
#ifdef _DEBUG
	freopen("r711a.in", "r", stdin);
#endif

	ios_base::sync_with_stdio(0); 

	int n;
	cin >> n;
	vector<string> lines(n);
	for (auto& l : lines)
		cin >> l;

	bool bFound = false;
	for (auto& l : lines) {
		if (l.substr(0, 2) == "OO") {
			l[0] = l[1] = '+';
			bFound = true; 
			break;
		}
		if (l.substr(3, 2) == "OO") {
			l[3] = l[4] = '+';
			bFound = true;
			break;
		}
	}
	cout << (bFound ? "YES" : "NO") << endl;
	if (bFound) {
		for (auto& l : lines)
			cout << l << endl;
	}

	return 0;
}
