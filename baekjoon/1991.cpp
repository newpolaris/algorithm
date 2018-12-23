#include <cstdio>
#include <map>
#include <algorithm>
std::map<char, std::pair<char, char>> tree;
void preorder(char n) {
    if (n == '.') return;
    printf("%c", n);
    preorder(tree[n].first);
    preorder(tree[n].second);
}

void inorder(char n) {
    if (n == '.') return;
    inorder(tree[n].first);
    printf("%c", n);
    inorder(tree[n].second);
}

void postorder(char n) {
    if (n == '.') return;
    postorder(tree[n].first);
    postorder(tree[n].second);
    printf("%c", n);
}

int main() {
#ifdef _DEBUG
    freopen("1991.in", "r", stdin);
#endif
    int n; char a[2], b[2], c[2];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s %s %s", a, b, c);
        tree[a[0]] = {b[0], c[0]};
    }
    preorder('A');  printf("\n");
    inorder('A');   printf("\n");
    postorder('A'); printf("\n");

    return 0;
}
