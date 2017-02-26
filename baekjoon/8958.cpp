#include <iostream>
#include <string>
#include <vector>

#define all(x) (x).begin(), (x).end()

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	int t;
	cin >> t;
	while (t--) {
		vector<int> score;
		string str;
		cin >> str;
		for (auto s : str)
			score.push_back(s == 'O');
		int c = 1, total = 0;
		for (int i = 0; i < score.size(); i++) {
			if (score[i]) {
				total += c++;
			} else {
				c = 1;
			}
		}
		cout << total << endl;
	}
	return 0;
}
