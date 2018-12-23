#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main()
{
#ifdef _DEBUG
	freopen("920b0.in", "r", stdin);
#endif
	int t, n, k, x, bed; 
	cin >> t;
	while (t--) {
		cin >> n;
		vector<int> arrive(n, 0), leave(n, 0);
		for (int i = 0; i < n; i++)
			cin >> arrive[i] >> leave[i];
		std::vector<int> occupy(n, 0);
		priority_queue<int> queue;
		for (int i = 1; i <= 5000; i++)
			queue.push(-i);

		for (int i = 0; i < n; i++)
		{
			while (!queue.empty())
			{
				int pass = -queue.top();
				if (arrive[i] <= pass)
					break;
				queue.pop();
			}
			int pass = -queue.top();
			if (queue.empty()) break;
			if (leave[i] < pass)
				continue;
			occupy[i] = pass;
			queue.pop();
		}
		for (int i = 0; i < n; i++)
			cout << occupy[i] << " \n"[i == n-1];
	}
	return 0;
}
