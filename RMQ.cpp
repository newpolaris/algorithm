#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <random>
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

		// 4n or 2*NextPot(n)
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
		// 두 구간이 겹치지 않으면 아주 큰 값을 반환 한다. 무시됨
		if (right < nodeLeft || nodeRight < left) 
			return N;
		if (left <= nodeLeft && nodeRight <= right)
			return range[node];
		int mid = (nodeLeft + nodeRight) / 2;
		return func(query(left, right, node * 2, nodeLeft, mid),
				   query(left, right, node * 2 + 1, mid + 1, nodeRight));
	}

	// array[index] = newValue로 바뀌었을 때 node를 루트로 하는
	// 구간 트리를 갱신하고 노드가 표현하는 구간의 최소치를 반환한다.
	int update(int index, int newValue,
				int node, int nodeLeft, int nodeRight) {
		// index가 노드가 표현하는 구간과 상관없는 경우엔 무시한다.
		if (index < nodeLeft || nodeRight < index)
			return range[node];
		// 트리의 리프까지 내려온 경우
		if (nodeLeft == nodeRight) return range[node] = newValue;
		int mid = (nodeLeft + nodeRight) / 2;
		return range[node] = func(
				update(index, newValue, node*2, nodeLeft, mid),
				update(index, newValue, node*2+1, mid+1, nodeRight));
	}

	// update()를 외부에서 호출하기 위한 인터페이스
	int update(int index, int newValue) {
		return update(index, newValue, 1, 0, n-1);
	}
};

int main()
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(1, 1000);

	vector<int> h(10);
	generate(begin(h), end(h), bind(dis, gen));

	RMQ MIN(h, [](int a, int b) { return min(a, b); }, numeric_limits<int>::max());
	RMQ MAX(h, [](int a, int b) { return max(a, b); }, numeric_limits<int>::min());

	copy(begin(h), end(h), ostream_iterator<int>(cout, " "));
	cout << endl;

	cout << "MIN " << MIN.query(0, h.size() - 1) << endl;
	cout << "MAX " << MAX.query(0, h.size() - 1) << endl;

	return 0;
}

