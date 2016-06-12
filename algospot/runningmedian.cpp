#include <iostream>
#include <queue>
#include <algorithm>
#include <queue>
#include <vector>
#include <functional>
#include <iostream>

using namespace std;

int main()
{
#ifdef _DEBUG
	freopen("runningmedian.in", "r", stdin);
#endif
	int C, N, a, b;
	cin >> C;
	while (C--) {
		cin >> N >> a >> b;
		int m = 20090711;
		vector<int> L(N);
		L[0] = 1983;
		for (int i = 1; i < N; i++) 
			L[i] = ((long long)L[i-1]*a+b) % m;

		priority_queue<int> Min, Max;
		Min.push(-987654321);
		Max = Min;

		auto insert = [&](int v) {
			if (-Max.top() <= v) Max.push(-v);
			else Min.push(v);
			if (Max.size() >= Min.size() + 2) {
				Min.push(-Max.top()); 
				Max.pop();
			}
			else if (Min.size() >= Max.size() + 2) {
				Max.push(-Min.top()); 
				Min.pop();
			}
		};
		auto median = [&]() { 
			return Min.size() >= Max.size() ? Min.top() : -Max.top();
		};
		int sum = 0;
		for (int i = 0; i < N; i++) {
			insert(L[i]);
			sum = (sum + median()) % m;
		}
		cout << sum << endl;
	}
}
