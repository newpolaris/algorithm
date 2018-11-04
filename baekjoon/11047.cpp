#include <iostream>
#include <string.h>
#include <vector>

#define forn(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define fori(i, a, b) for (int i = (a), i##_end_ = (b); i > i##_end_; --i)

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("11047.in", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	int n, k;	
	cin >> k >> n;
    std::vector<int> coins(k);
    for (auto& in : coins)
        cin >> in;
    int cnt = 0;
    for (auto rit = coins.rbegin(); rit != coins.rend(); rit++)
    {
        cnt += n / *rit;
        n = n % *rit;
    }
    cout << cnt << endl;
    return 0;
}
