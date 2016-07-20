#include <iostream>
#include <stack>
#include <string>
#include <map>

using namespace std;

map<char, char> close = {{']','['}, {')','('}, {'}','{'}};

bool check(string str)
{
	stack<char> s;
	for (char c : str)
	{
		if (close.find(c) == close.end())
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
