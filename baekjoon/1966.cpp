#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
    int c, n, t;
#ifdef _DEBUG
	freopen("1966.in", "r", stdin);
#endif
    cin >> c;
    while (c--) {
        cin >> n >> t;
        std::vector<int> v(n);
        for (auto& i : v)
            cin >> i;
        std::vector<int> s(v);
        std::sort(s.begin(), s.end(), std::greater<int>());

        int cnt = 1, k = 0;
        for (int i = 0;; i = (i+1) % n)
        {
            if (v[i] == s[k]) {
                k++;
                if (i == t)
                    break;
                cnt++;
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}
