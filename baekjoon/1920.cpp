#include <iostream>
#include <unordered_set>

#define forn(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define fori(i, a, b) for (int i = (a), i##_end_ = (b); i > i##_end_; --i)

using namespace std;

int main() {
	int n, a, k;
	scanf("%d",&n);
	unordered_set<int> set;
	set.reserve(n);
	while (n--) {
		scanf("%d",&a);
		set.insert(a);
	}
	cin >> k;
	while (k--) {
		scanf("%d",&a);
		printf("%lu\n", set.count(a));
	}
	
	return 0;
}
