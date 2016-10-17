#include <iostream>
#include <vector>

using namespace std;

struct FenwickTree
{
	vector<int> data;
	// 1부터 시작
	FenwickTree(int n) : data(n+1) {}

	// A[pos]에 val 을 더한다.
	void add(int pos, int val) {
		++pos;
		while (pos < data.size()) {
			data[pos] += val;
			// Ex: A[5] - 101, 110, 1000, 10000
			// 가장 오른쪽의 1을 스스로에게 더한다
			pos += (pos & -pos);
		}
	}

	// A[0..pos]의 부분 합을 구한다.
	int sum(int pos) {
		// 인덱스가 1 부터 시작한다고 생각하자
		pos++;
		int ret = 0;
		while (pos > 0) {
			ret += data[pos];
			// 다음 구간을 찾기 위해 최종 비트를 지운다.
			pos &= (pos - 1);
		}
		return ret;
	}
};

int main()
{
#ifdef _DEBUG
	freopen("measuretime.in", "r", stdin);
#endif
	int C, N, e;
	scanf("%d", &C);
	while (C--) {
		scanf("%d", &N);
		FenwickTree tree(1000000);
		long long c = 0;
		for (int i = 0; i < N; i++) {
			scanf("%d", &e);
			c += tree.sum(1000000) - tree.sum(e);
			tree.add(e, 1);
		}
		printf("%lld\n", c);
	}

	return 0;
}
