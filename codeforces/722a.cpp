#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
#ifdef _DEBUG
	freopen("722a.in", "r", stdin);
#endif

	int f, h, m;
	char d;
	cin >> f;
	cin >> h >> d >> m;

	if (m >= 60)
		m %= 10;
	if (h >= f && f == 24) {
		h %= 10;
	} else if ((h == 0 || h > f) && f == 12) {
		if (h == 0) 
			h = 1;
		else {
			h %= 10;
			if (h == 0)
				h = 10;
		}
	}

	cout << setw(2) << setfill('0') << h;
	cout << d;
	cout << setw(2) << setfill('0') << m;
	cout << endl;

	return 0;
}
