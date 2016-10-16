#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <limits>

using namespace std;

unsigned int NextPot(unsigned int n)
{
	n--;
	n |= n >> 1; n |= n >> 2;
	n |= n >> 4; n |= n >> 8;
	n |= n >> 16;
	n++;

	return n;
}

typedef std::function<int(int, int)> UnaryFunction;
struct RMQ
{
	typedef const vector<int>& CAR;
	int n;
	int N;
	UnaryFunction func;
	vector<int> range;

	RMQ(CAR arr, UnaryFunction f, int _N)
	{
		func = f;
		n = arr.size();
		N = _N;

		range.resize(NextPot(n) << 1);
		init(arr, 0, n - 1, 1);
	}

	int init(CAR arr, int left, int right, int node)
	{
		int mid = (left + right) / 2;
		if (left == right)
			return range[node] = arr[left];
		return range[node] = func(init(arr, left, mid, node * 2), init(arr, mid+1, right, node * 2 + 1));
	}

	int query(int left, int right)
	{
		return query(left, right, 1, 0, n - 1);
	}

	int query(int left, int right, int node, int nodeLeft, int nodeRight)
	{
		if (right < nodeLeft || nodeRight < left) 
			return N;
		if (left <= nodeLeft && nodeRight <= right)
			return range[node];
		int mid = (nodeLeft + nodeRight) / 2;
		return func(query(left, right, node * 2, nodeLeft, mid),
				   query(left, right, node * 2 + 1, mid + 1, nodeRight));
	}

};

int main()
{
	cin.sync_with_stdio(false);
	int c, n, q, a, b;
	cin >> c;

	while (c--)
	{
		cin >> n >> q;
		vector<int> h(n);
		for (auto &e : h)
			cin >> e;

		RMQ MIN(h, [](int a, int b) { return min(a, b); }, numeric_limits<int>::max());
		RMQ MAX(h, [](int a, int b) { return max(a, b); }, numeric_limits<int>::min());

		while (q--)
		{
			cin >> a >> b;
			int A = MIN.query(a, b);
			int B = MAX.query(a, b);
			cout << B - A << endl;
		}
	}

	return 0;
}
