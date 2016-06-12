#include <cstdio>
#include <cstring>

char S[1000001];
int N[1000000];

int main()
{
#ifdef _DEBUG
	freopen("zeroone.in", "r", stdin);
#endif
	scanf("%s", S);
	int L = strlen(S);
	int K = 0, A, a, b;
	N[0] = K;
	for (int i = 1; i < L; i++) {
		if (S[i] != S[i-1]) ++K;
		N[i] = K;
	}
	scanf("%d", &A);
	while (A--)
	{
		scanf("%d%d", &a, &b);
		printf("%s\n", (N[a] != N[b]) ? "No" : "Yes");
	}

	return 0;
}

