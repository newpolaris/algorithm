#include <stdio.h>
#include <vector>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    vector<int> in(n);
    for (auto& i : in)
        scanf("%d", &i);
    vector<int> r;
    r.reserve(n);
    for (int i = n; i >= 1; i--) {
        auto it = r.begin();
        std::advance(it, in[i - 1]);
        r.insert(it, 1, i);
    }
    for (int i = 0; i < n; i++)
        printf("%d%c", r[i], " \n"[i+1 == n]);
    return 0;
}
