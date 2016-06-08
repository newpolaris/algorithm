#include <iostream>
#include <string>

using namespace std;

int main()
{
#if _DEBUG
	freopen("mispell.in", "r", stdin);
#endif
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		int a;
		string K;
		cin >> a >> K;
		cout << t << " ";
		for (int k = 0; k < K.size(); k++)
			if (k != a-1)
				cout << K[k];
		cout << endl;
	}

	return 0;
}
