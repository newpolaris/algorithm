#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	int arr[n+1];
	arr[0] = arr[1] = 1;
	for (int i = 2; i <= n; i++)
		arr[i] = (arr[i-1] + arr[i-2]) % 10007;
	printf("%d\n", arr[n]);
	return 0;
}
