#include <iostream>
#include <vector>
#include <limits>

using namespace std;

using vi = vector<int>;

const int MAX_INT = numeric_limits<int>::max();

struct RMQ
{
	vi data;
	int n;
	RMQ(vi& arr) {
		n = arr.size();
		data.resize(n * 4);
		init(arr, 1, 0, n - 1);
	}

	int init(vi& arr, int node, int left, int right) {
		if (left == right)
			return data[node] = arr[left];
		int mid = (left + right) / 2;
		return data[node] = min(init(arr, node*2, left, mid),
						 		init(arr, node*2+1, mid+1, right));
	}

	int query(int left, int right, int node, int nodeLeft, int nodeRight) {
		if (left > nodeRight || nodeLeft > right)
			return MAX_INT;

		if (left <= nodeLeft && nodeRight <= right) {
			return data[node];
		}

		int mid = (nodeLeft + nodeRight) / 2;
		return min(query(left, right, node*2, nodeLeft, mid),
				   query(left, right, node*2+1, mid+1, nodeRight));

		return 0;
	}

	int query(int left, int right) { 
		if (left > right)
			swap(left, right);
		return query(left, right, 1, 0, n - 1);
	}
};

vector<vi> Node;
int numToidx[100000];

void traversal(vi& path, vi& depth, int cur, int d) {
	path.push_back(cur);
	depth.push_back(d);
	numToidx[cur] = path.size() - 1;
	for (auto& child : Node[cur]) {
		traversal(path, depth, child, d+1);
		path.push_back(cur);
		depth.push_back(d);
	}
}

int main() {
#ifdef _DEBUG
	freopen("familytree.in", "r", stdin);
#endif

	int C, N, Q, a, b, e;

	scanf("%d", &C);
	while (C--) {
		scanf("%d%d", &N, &Q);
		Node = vector<vi>(N);
		for (int i = 1; i < N; i++) { 
			scanf("%d", &e);
			Node[e].push_back(i);
		}
		vi path, depth;
		traversal(path, depth, 0, 0);

		RMQ rmq(depth);
		for (int i = 0; i < Q; i++) {
			scanf("%d %d", &a, &b);
			int minDepth = rmq.query(numToidx[a], numToidx[b]);
			int da = depth[numToidx[a]];
			int db = depth[numToidx[b]];
			printf("%d\n", da + db - minDepth * 2);
		}
	}

	return 0;
}
