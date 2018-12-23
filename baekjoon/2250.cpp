#include <cstdio>
#include <algorithm>

int cnt = 1;
int left[10001];
int right[10001];
int level[10001];

void Inorder(int idx, int lv) {
    int l = left[idx], r = right[idx];
    if (l > 0) Inorder(l, lv+1);
    level[cnt++] = lv;
    if (r > 0) Inorder(r, lv+1);
}

int main() {
#ifdef _DEBUG
	freopen("2250.in", "r", stdin);
#endif
    int n, t;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d %d %d", &t, &left[i], &right[i]);

    Inorder(1, 1);

    int lvMin[10001] = { 0, };
    int dist[10001] = { 0, };

    for (int i = 1; i <= n; i++) {
        int l = level[i];
        int& min = lvMin[l];
        if (min <= 0) min = i;
        else
            dist[l] = i - min + 1;
    }
    auto it = std::max_element(dist+1, dist+n+1);
    auto l = std::distance(dist, it);
    printf("%ld %d\n", l, *it);

    return 0;
}
