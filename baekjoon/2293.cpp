#include <iostream>
#include <string.h>
#include <vector>

#define forn(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define fori(i, a, b) for (int i = (a), i##_end_ = (b); i > i##_end_; --i)

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("2293.in", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	int n, k;	
	cin >> k >> n;
	vector<int> coins(k);
	for (auto& c : coins) cin >> c;

    /*
     * 자꾸, 3*1, 3*2, 3*3 이렇게 생각하는데, 
     * 하나의 종류만을 추가로 사용해서 n을 채우는것을
     * k 종류로 반복한다고 생각하면,
     *
     * coin[n - 3] 에서 그냥 3원짜리 하나 더 쓴거라
     * 방법수는 그대로 이다. 그러므로 이전 것에서 더해주면 됨.
	 */
    int cache[10001];
	memset(cache, 0, sizeof(cache));
	cache[0] = 1;
    for (int j = 0; j < k; j++)
        for (int i = coins[j]; i <= n; i++)
			cache[i] += cache[i - coins[j]];
	cout << cache[n] << endl;
	return 0;
}
