#include <stdio.h>
#include <vector>

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	std::vector<bool> arr(m);
	for (int i = 0; i < n; i++)
	{
		int l, r;
		scanf("%d %d", &l, &r);
		for (int j = l - 1; j <= r - 1; j++)
			arr[j] = true;
	}
	int count = 0;
	for (int j = 0; j < m; j++)
	{
		if (arr[j] == false)
			count++;
	}
	printf("%d\n", count);
	for (int i = 0; i < m; i++)
		if (arr[i] == false)
			printf("%d ", i+1);
	printf("\n");
	return 0;
}
