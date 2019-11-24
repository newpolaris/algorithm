#include <cstdio>
#include <string>
#include <cmath>

using namespace std;

void solve(int n, int a, int b, int c)
{
    if (n == 0)
        return;

    solve(n-1, a, c, b);
    printf("%d %d\n", a, c);
    solve(n-1, b, a, c);
}

int main()
{
    int n;
    scanf("%d", &n);
    string s = to_string(pow(2, n));
    int idx = s.find('.');
    s = s.substr(0, idx);
    s[s.length() - 1] -= 1;
    printf("%s\n", s.c_str());
    if (n <= 20) solve(n, 1, 2, 3);
    return 0;
}
