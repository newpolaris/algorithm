#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
int main() {
	vector<string> resist = { "black", "brown", "red", "orange",
		"yellow", "green", "blue", "violet", "grey", "white" };
	vector<pair<string, int>> resistPair;
	for (int i = 0; i < resist.size(); i++) 
		resistPair.push_back({resist[i], i});
	sort(resistPair.begin(), resistPair.end());
	auto find = [&](string name) {
		int lo = 0, hi = resistPair.size() - 1, mid;
		while (lo <= hi) {
			mid = lo + (hi-lo)/2;
			int compare = resistPair[mid].first.compare(name);
			if (compare == 0) break;
			else if (compare < 0) lo = mid + 1;
			else hi = mid - 1;
		}
		return resistPair[mid].second;
	};
	string a, b, c;
	cin >> a >> b >> c;
	long long num = find(a)*10 + find(b);
	num *= (long long)pow(10, find(c));
	cout << num << endl;

	return 0;
}
