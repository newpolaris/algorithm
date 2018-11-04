#include <iostream>
#include <string.h>
#include <vector>

#define forn(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define fori(i, a, b) for (int i = (a), i##_end_ = (b); i > i##_end_; --i)

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("2294.in", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	int n, k;	
	cin >> k >> n;
    int cache[10001];
    memset(cache, -1, sizeof(cache));
    std::vector<int> coins(k);
    for (auto& in : coins)
        cin >> in;
    cache[0] = 0;
    for (int j = 0; j < k; j++)
    {
        for (int i = coins[j]; i <= n; i++)
        {
            int r = i - coins[j];
            if (cache[r] < 0)
                continue;
            if (cache[i] >= 0)
                cache[i] = min(cache[i], cache[r] + 1);
            else
                cache[i] = cache[r] + 1;
        }
    }

    cout << cache[n] << endl;
    return 0;
}
