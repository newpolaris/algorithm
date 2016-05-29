#include <iostream>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;
typedef vector<int> vi;

int main()
{

	int T, HP, MP, A, D, HP2, MP2, A2, D2;
	scanf("%d", &T);

	while (T--)
	{
		scanf("%d%d%d%d%d%d%d%d", &HP, &MP, &A, &D, &HP2, &MP2, &A2, &D2);

		HP = max(HP+HP2, 1);
		MP = max(MP+MP2, 1);
		A = max(A+A2, 0);
		D = D + D2;

		int S = HP + 5*MP + 2*A + 2*D;
		printf("%d\n", S);
	}

	return 0;
}

