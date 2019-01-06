#include <algorithm>
#include <vector>
#include <functional>
int main() {
    int n, a;
    scanf("%d", &n);
    std::vector<int> tree(n);
    for (auto& t : tree) scanf("%d", &t);
    std::sort(tree.begin(), tree.end(), std::greater<int>());
    int days = 0;
    for (int i = 0; i < n; i++) {
        days = std::max(days, tree[i] + i + 1);
    }
    printf("%d\n", days + 1);
    return 0;
}
