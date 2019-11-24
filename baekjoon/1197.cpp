#include <cstdio>
#include <vector>
#include <algorithm>

//
// Knuskal's algorithm, MST, union-find (disjoint-set)
//
// 크루스칼 이다, TSP에 응용은 algospot/tsp1.cpp
// (disjoint-set의 class 구현도 거기에 존재)
// 
// 간단한 설명자료는, 
// https://www.crocus.co.kr/733
// https://victorydntmd.tistory.com/101?category=686701
//
// knuskal이 O(E lg E)
// prim이 O(E lg V)
//
// 라는데, 단순 블로그 글이므로 확인 필요

const int length = 10'001;
int root_[length];
int rank_[length];

int find(int x) {
    if (root_[x] != x)
        root_[x] = find(root_[x]);
    return root_[x];
}

bool merge(int x, int y) {

    x = find(x);
    y = find(y);

    // 두 값의 root 가 같으면 (이미 같은 트리) 합치지 않는다.
    if (x == y)
        return false;

    // 항상 높이가 더 낮은 트리를 높이가 높은 트리 밑에 넣는다.
    // 같아도 x 에 달아버린다 (y의 root를 x로 변경한다)
    if (rank_[x] < rank_[y])
        root_[x] = y;
    else
        root_[y] = x;

    if (rank_[x] == rank_[y])
        rank_[x]++;
    return true;
}

using namespace std;

struct KS {
    int from, to, val;
};
vector<KS> edge;

int main() {
    int v, e;
    scanf("%d %d", &v, &e);
    for (int i = 0; i < length; i++) {
        root_[i] = i;
        rank_[i] = 0;
    }
    for (int i = 0; i < e; i++) {
        KS ks;
        scanf("%d %d %d", &ks.from, &ks.to, &ks.val);
        edge.emplace_back(ks);
    }

    sort(edge.begin(), edge.end(), [](const KS& a, const KS& b) { return a.val < b.val; });

    int res = 0;
    for (int i = 0; i < e; i++) {
        if (merge(edge[i].from, edge[i].to))
            res += edge[i].val;
    }
    printf("%d\n", res);

    return 0;
}
