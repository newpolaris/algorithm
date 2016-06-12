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
		int num = 1;
		auto insert = [&](int v) {
			if (num & 1) Min.push(v);
			else Max.push(-v);
			if (num > 2) {
				while (Min.top() > -Max.top()) {
					int A = Min.top(), B = -Max.top();
					Min.pop(); Min.push(B);
					Max.pop(); Max.push(-A);
				}
			}
			num++;
		};
		auto median = [&]() { return Min.top(); };
		int sum = 0;
		for (int i = 0; i < N; i++) {
			insert(L[i]);
			sum = (sum + median()) % m;
		}
		cout << sum << endl;
	}
}
