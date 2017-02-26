#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

#define all(x) (x).begin(), (x).end()

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	vector<int> score(4);
	vector<int> total;
	for (int i = 0; i < 5; i++) {
		for (auto& s : score) cin >> s;
		total.push_back(accumulate(all(score), 0));
	}
	auto it = max_element(all(total));
	cout << distance(total.begin(), it)+1 << " " << *it << endl;
	return 0;
}
