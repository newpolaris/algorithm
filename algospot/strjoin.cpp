#include <iostream>
#include <queue>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("strjoin.in", "r", stdin);
#endif

	int C, N, T;
	cin >> C;
	while (C--) { 
		priority_queue<int> Q;
		cin >> N;
		while (N--) {
			cin >> T;
			Q.push(-T);
		}
		int Cost = 0;
		while (Q.size() > 1)
		{
			int a = Q.top(); Q.pop();
			int b = Q.top(); Q.pop();
			int C = a + b;
			Q.push(C); Cost += C;
		}
		cout << (-Cost) << endl;
	}
	return 0;
}

