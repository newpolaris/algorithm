#include <iostream>
#include <string>

using namespace std;

int main()
{
#if _DEBUG
	freopen("endians.in", "r", stdin);
#endif
	int T;
	cin >> T;
	while (T--)
	{
		unsigned int a;
		cin >> a;
		char* t = reinterpret_cast<char*>(&a);
		swap(t[0], t[3]);
		swap(t[1], t[2]);
		cout << a << endl;
	}

	return 0;
}
