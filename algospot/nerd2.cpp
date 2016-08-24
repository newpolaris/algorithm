#include <iostream>
#include <iterator>
#include <map>

using namespace std;

map<int, int> v;

int insert(int p, int q) {
	auto upper = v.lower_bound(p);

	if (upper != v.end() && q < upper->second)
		return v.size();

	auto lower = upper;
	while (lower != v.begin()) {
		if (prev(lower)->second > q)
			break;
		lower--;
	}
	v.erase(lower, upper);
	v[p] = q;

	return v.size();
}

int main()
{
#ifdef _DEBUG
	freopen("nerd2.in", "r", stdin);
#endif

	int c, n, p, q;
	scanf("%d", &c);
	while (c--) {
		scanf("%d", &n);
		v.clear();
		int count = 0;
		while (n--) {
			scanf("%d%d", &p, &q);
			count += insert(p, q);
		}
		printf("%d\n", count);
	}
	return 0;
}
