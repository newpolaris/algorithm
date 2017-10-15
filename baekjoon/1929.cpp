#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	const int L = 1000001;
	vector<bool> primes(L, true);
	primes[0] = primes[1] = false;
	for (int i = 2; i*i < L; i++) {
		if (primes[i]) { 
			for (int k = i*i; k < L; k += i) {
				primes[k] = false;
			}
		}
	}
	int m, n;
	scanf("%d%d", &m, &n);
	for (int i = m; i <= n; i++) {
		if (primes[i])
			printf("%d\n", i);
	}
	return 0;
}
