#include <iostream>
#include <iomanip>

using namespace std;

double measure[] = { 2.2046, 0.4536, 0.2642, 3.7854 };
string unit[] = { "lb", "kg", "g", "l" };

int main()
{
#ifdef _DEBUG
	freopen("convert.in", "r", stdin);
#endif
	auto idx = [](string m) {
		if (m == "kg") return 0;
		if (m == "lb") return 1;
		if (m == "l") return 2;
		return 3;
	};
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++)
	{
		double v;
		string mea;
		cin >> v >> mea;
		int k = idx(mea);
		cout << i << " "
			<< fixed << setprecision(4)
			<< (v * measure[k])
			<< " " << unit[k] << endl;
	}

	return 0;
}

