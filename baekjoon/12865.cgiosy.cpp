//cgiosy's

#include <cstdio>
#include <algorithm>
#define M 100001
int main() {
	int d[M]={}, n, m, r=0;
	scanf("%d%d", &n, &m);
	for(int v, c; ~scanf("%d%d", &v, &c);)
		for(int j=M; j>=v; j—)
			d[j]=std::max(d[j], d[j-v]+c);
	printf("%d", d[m]);
}
