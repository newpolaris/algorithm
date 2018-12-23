#include <iostream>
#include <string.h>
#include <vector>
#include <string>
#include <strstream>

#define forn(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define fori(i, a, b) for (int i = (a), i##_end_ = (b); i > i##_end_; --i)

using namespace std;

int cache[1001][1001];

int main() {
#ifdef _DEBUG
	freopen("9251.in", "r", stdin);
#endif
	ios::sync_with_stdio(0);
    string a, b;
    cin >> a >> b;
    memset(cache, 0, sizeof(cache));
    for (int x = a.size() - 1; x >= 0; x--)
    for (int y = b.size() - 1; y >= 0; y--)
    {
        int m = max(cache[x+1][y], cache[x][y+1]);
        int n = cache[x+1][y+1] + (a[x] == b[y]);
        cache[x][y] = max(n, m);
    }
    cout << cache[0][0] << endl;

    strstream str;
    int x = 0, y = 0; 
    while (cache[x][y] != 0)
    {
        if (cache[x][y] == cache[x][y+1]) y++;
        else if (cache[x][y] == cache[x+1][y]) x++;
        else
        {
            str << a[x];
            x++; y++;
        }
    }
    cout << str.str() << endl;
    return 0;
}
