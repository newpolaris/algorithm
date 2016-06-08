#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

string numStr[11] = {
	"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"
};

int convert(string s) {
	sort(s.begin(), s.end());
	for (int i = 0; i <= 10; i++) 
		if (s == numStr[i])
			return i;
	return -100;
}

int op(int a, int b, char oper)
{
	switch (oper)
	{
		case '+': return a + b;
		case '-': return a - b;
		case '*': return a * b;
	}
	return -100;
}

int main()
{
#ifdef _DEBUG
	freopen("xhaeneung.in", "r", stdin);
#endif
	for (int i = 0; i <= 10; i++)
		sort(numStr[i].begin(), numStr[i].end());

	int T;
	cin >> T;
	while (T--) {
		vector<string> str(5);
		for (auto& s : str)
			cin >> s;
		cout << (op(convert(str[0]), convert(str[2]), str[1][0]) == convert(str[4]) ? "Yes" : "No") << endl;
	}

	return 0;
}

