#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int main()
{
#ifdef _DEBUG
    freopen("10818.in", "r", stdin);
#endif

    int n;
    scanf("%d", &n);
    std::vector<int> a(n);
    for (auto& i : a)
        scanf("%d", &i);
    auto k = std::minmax_element(a.begin(), a.end());
    printf("%d %d\n", *k.first, *k.second);

    return 0;
}
