#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
#ifdef _DEBUG
	freopen("920a0.in", "r", stdin);
#endif
	int t, n, k, x, bed; 
	cin >> t;
	while (t--) {
		cin >> n >> k;
		vector<int> beds(n, 200);
		for (int i = 0; i < k; i++) 
		{
			cin >> x;
			for (int bed = 0; bed < n; bed++)
				beds[bed] = min(beds[bed], abs(x - 1 - bed) + 1); 
		}
		cout << *max_element(beds.begin(), beds.end()) << endl;
	}
	return 0;
}
