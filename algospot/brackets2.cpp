#include <iostream>
#include <stack>
#include <string>

using namespace std;

char close[256];

bool check(string str)
{
	auto isopen = [](char c) { return c == '[' || c == '(' || c == '{'; };

	stack<char> s;
	for (char c : str)
	{
		if (isopen(c))
			s.push(c);
		else
		{
			if (s.empty() || s.top() != close[c]) 
				return false;
			s.pop();
		}
	}

	return s.empty();
}

int main()
{
#if _DEBUG
	freopen("brackets2.in", "r", stdin);
#endif
	close[')'] = '(';
	close['}'] = '{';
	close[']'] = '[';

	int C;
	cin >> C;
	while (C--)
	{
		string str;
		cin >> str;
		cout << (check(str) ? "YES" : "NO") << endl;
	}
	return 0;
}
