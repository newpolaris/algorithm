#include <cstdio>
#include <string.h>

void merge(char* a, char* b, int s, int m, int e) {
	int i0 = s, i1 = m+1;
	int r = s;
	while (i0 <= m || i1 <= e) {
		// 내림차순 정렬
		if (i0 > m || (i1 <= e && a[i0] > a[i1])) b[r++] = a[i1++];
		else b[r++] = a[i0++];
	}
	for (int i = s; i <= e; i++) 
		a[i] = b[i];
}

void split_merge(char* a, char* b, int s, int e) {
	int m = (s+e)/2;
	if (s < e) {
		split_merge(a, b, s, m);
		split_merge(a, b, m+1, e);
		merge(a, b, s, m, e);
	}
}

void sort(char* a, int s, int e) {
	char temp[e-s];
	split_merge(a, temp, s, e-1); 
}

int main() {
	char buf[20] = {0,};
	scanf("%s", buf);
	sort(buf, 0, strlen(buf));
	printf("%s\n", buf);
	return 0;
}
