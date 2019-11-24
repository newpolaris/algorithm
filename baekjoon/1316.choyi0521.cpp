#include<stdio.h>
#include<string.h>
int n,p[200],res;
char str[101];
int main() {
	scanf("%d", &n);
	res = n;
	for (int i = 0; i < n; i++) {
		memset(p, -1, sizeof(p));
		scanf("%s", str);
		for (int j = 0; str[j]; j++)
			if (p[str[j]] == -1 || p[str[j]] == j - 1) p[str[j]] = j;
			else { res--; break; }
	}
	printf("%d", res);
	return 0;
}
