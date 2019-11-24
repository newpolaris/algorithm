#include <cstdio>
#include <set>

using namespace std;
int main() {
    int n = 10, d;
    set<int> s;
    while (n--) {
        scanf("%d", &d);
        s.insert(d%42);
    }
    printf("%lu\n", s.size());
    return 0;
}
