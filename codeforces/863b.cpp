#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>

using namespace std;

int sum(int s, int e, const vector<int>& K)
{
	int sum = 0;
	for (int i = s; i < e; i+=2)
		sum += std::abs(K[i] - K[i+1]);
	return sum;
}

int main() {
#ifdef _DEBUG
	// freopen("863a.in", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vector<int> K(n*2);
	for (auto& k : K)
		cin >> k;
	sort(K.begin(), K.end());
	int m = 50*1000;
	for (int a = 0; a < n*2; a++) {
		for (int b = a+1; b < n*2; b++) {
			int k = -1;
			int d = 0;	
			int f = 0;
			while (k < n*2) {
				k++;
				if (k == a || k == b) 
					continue;
				if (f != 0) 
				{
					d += abs(K[k] - f);
					f = 0;
				}
				else
				{
					f = K[k];
				}
			}
			m = min(d, m);
		}
	}
	cout << m << endl;
	return 0;
}
