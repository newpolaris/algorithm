#include <cstdio>
int main() {
	long long n, m, k;
	scanf("%lld%lld", &n, &m);
	k = n - m;
	printf("%lld\n", (k < 0 ? -k : k));
	return 0;
}
