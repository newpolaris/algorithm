#include <iostream>
#include <string>

using namespace std; 

int main() {
#ifdef _DEBUG
	freopen("712b.in", "r", stdin);
#endif

	string s;
	cin >> s;

	int m = -1;
	if (s.size() % 2 == 0) {
		m = 0;
		int plan[2] = {0, };
		for (int i = 0; i < s.size(); i++) {
			switch (s[i])
			{
			case 'R': plan[0]++; break;
			case 'L': plan[0]--; break;
			case 'U': plan[1]++; break;
			case 'D': plan[1]--; break;
			}
		}
		m += abs(plan[0]);
		m += abs(plan[1]);
		m /= 2;
	}
	cout << m << endl;
	
	return 0;
}
