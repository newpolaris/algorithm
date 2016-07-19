#include <iostream>
#include <cstring>

using namespace std;

int main()
{
#ifdef _DEBUG
	freopen("josephus.in", "r", stdin);
#endif

	int C;
	cin >> C;
	while (C--)
	{
		// j: last survivor, k: second-last survivor
		int j, k, N, K;
		cin >> N >> K;

		/*
		 * 첫번째 요소를 뺸다. 
		 * 해당 operator 이전의 상태를 만들기 위해
		 * k - 1번 shift 하여 shift 이전의 상태로 복귀하고
		 * 요소를 뺀걸 돌리기 위해 1 칸 shift
		 * 1: a b
		 * 2: * a b			-> 1 a b
		 * 3: * a b *		-> 2 a b 1
		 * 4: * b * * a		-> 3 b 1 2 a
		 * 5: * * a * b *	-> 4 2 a 3 b 1
		 */
		// recurrence relation: j(n, k) = { j(n-1, k) + (k-1) } % (n-1) + 1
		j = 0, k = 1;
		for (int i = 2; i < N; i++)
		{
			j = (j + (K-1)) % (i) + 1;
			k = (k + (K-1)) % (i) + 1;
		}

		cout << min(j, k) + 1 << " " << max(j, k) + 1 << endl;
	}

	return 0;
}
