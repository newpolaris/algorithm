#include <iostream>
#include <vector>
#include <string>
#include <string.h>

#define REP(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

using namespace std;

vector<int> coins = { 1, 5, 10, 20, 50 };
int cache[10000][6];

/* 이렇게 된데는 식을 적지 않는 습관이 문제가 됬는 듯
 * count(n) = all i sum (count(n-coins(i)))
 * 생각하려 했는데 최갑부가 답변을 해버림
 * (1,1,5), (1,5,1), (5,1,1) 과 같이 순서 상관없이
 * 나와버리니 JMB에서의 순서를 정하는 루틴이 필요
 * count(n,i) = all i sum(count(n-coins(i),i))
 * 보통은, coins.cpp 에서 처럼
 * count(n,i) = count(n, i-1) + count(n-coins(i), i) 로 처리함.
 */
int exchangeCount(int remain, int nextI) {
	if (remain < 0) return 0;
	if (remain == 0) return 1;
	auto& ret = cache[remain][nextI];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = nextI; i < coins.size(); i++) {
		ret += exchangeCount(remain - coins[i], i);
	}
	return ret;
};

int main() {
#ifdef _DEBUG
	freopen("coinexchange0.in", "r", stdin);
#endif
	int n, k;
	cin >> n;
	memset(cache, -1, sizeof(cache));
	while (n--) {
		cin >> k;	
		cout << exchangeCount(k, 0) << endl;
	}
	return 0;
}
