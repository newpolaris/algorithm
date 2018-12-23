#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int main()
{
#ifdef _DEBUG
	freopen("920c1.in", "r", stdin);
#endif
	int n, a, i;
	scanf("%d", &n);
	vector<bool> sorted(n, false);
	vector<pair<int, int>> range;
	for (int t = 0; t < n; t++)
	{
		int o = t;
		scanf("%d", &a);
		a--;
		if (o < a) swap(o, a);
		if (o == a) continue;
		range.push_back({a, o});
	}
	string swappable;
	cin >> swappable;
	sort(range.begin(), range.end());
	vector<pair<int, int>> result;
    vector<pair<int, int> >::iterator it = range.begin();
    pair<int,int> current = *(it)++;
    while (it != range.end()){
       if (current.second >= it->first) {
           current.second = std::max(current.second, it->second); 
       } else {
           result.push_back(current);
           current = *(it);
       }
       it++;
    }
    result.push_back(current);
	bool cant = false;
	for (int t = 0; t < result.size(); t++)
	{
		for (int c = result[t].first; c < result[t].second; c++) {
			if (c == n - 1) continue;
			if (swappable[c] != '1') 
			{
				cant = true;
				break;
			}
		}
		if (cant) break;
	}
	if (cant) cout << "NO";
	else cout << "YES";
	cout << endl;
	return 0;
}
