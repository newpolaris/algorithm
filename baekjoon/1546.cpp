#include <cstdio>
#include <vector>
#include <algorithm>
int n;
int main() {
    scanf("%d", &n);
    std::vector<int> var(n);
    for (auto& v : var) scanf("%d", &v);
    auto maxVal = *std::max_element(var.begin(), var.end());
    double sum = 0.0;
    for (auto& v : var) {
        sum += double(v) / maxVal * 100;
    }
    auto avg = double(sum) / n;
    printf("%2.4f\n", avg);
    return 0;
}
