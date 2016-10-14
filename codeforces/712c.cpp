#include <iostream>
#include <vector>

using namespace std; 

int main() {
#ifdef _DEBUG
	freopen("712c.in", "r", stdin);
#endif

	int a, b;	
	cin >> a >> b;

	vector<int> t;
	t.push_back(b);
	t.push_back(b * 2 - 1);
	while (t.back() < a)
	{
		int n = t.size();
		t.push_back(t[n-1] + t[n-2] - 1);
	}
	cout << (t.size()+1) << endl;

	return 0;
}
