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

#include <iostream>
#include <string.h>
#include <vector>

#define forn(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define fori(i, a, b) for (int i = (a), i##_end_ = (b); i > i##_end_; --i)

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("../baekjoon/2293.in", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	int n, k;	
	cin >> n >> k;
	vector<int> coins(n);
	for (auto& c : coins) cin >> c;

	/*
	 * tag: FAIL, dp
	 *
	 * k원, 동전 현재 사용중인 index
	 *
	 * c[k+coin[i]][i] = c[k][i]
	 * c[k][i+1] = c[k][i]
	 *
	 * 사용안하고 넘길수 있어야 100원이 아닌 바로 500원으로 1000원 만들수 있다.
	 *
	 * 위에 식은 항상 증가하는 식이 아니라서 불편
	 * 돈을 기준으로 iterate 하도록 하여,
	 * c[k+coin[i]][i] = c[k][i]
	 * c[k+coin[i+5]][i+5] = c[k][i]
	 */
#ifdef _TEST
	int c[10001][100];
	memset(c, 0, sizeof(c));
	for (int i = 0; i < n; i++) 
		if (coins[i] <= k) c[coins[i]][i]++;

	for (int i = 1; i < k; i++) {
		for (int j = 0; j < n; j++) {
			for (int t = j; t < n; t++) {
				if (i+coins[t] > k) continue;
				c[i+coins[t]][t] += c[i][j];
			}
		}
	}
	int t = 0;
	for (int i = 0; i < n; i++) t += c[k][i];
	cout << t << endl;
#endif
	/*
	 * 위의 방법은 메모리도 문제고, O(n^2k)가 된다
	 * 그리고 초기 coin setting 도 필요하고 실수하기도 좋다
	 * 두번 세는 걸 막기 위해서 reculsive 방법에서 빌려온건데
	 * 깔끔한 방법 없는가?
	 * 특정 동전을 여러번 넣는 것. 돈은 증가하는 것
	 * 돈이 아니고 동전을 외각으로 돌리면?
	 *
	 * c[k+coin[i]] += c[k]
	 *
	 * 
	 */
	int c[10001];
	memset(c, 0, sizeof(c));
	c[0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j + coins[i] <= k; j++) {
			c[j + coins[i]] += c[j];
		}
	}
	cout << c[k] << endl;

	return 0;
}

//


