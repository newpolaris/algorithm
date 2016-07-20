#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

string str;
const string opening = "([", closing = ")]";
int cache[101];

int matching(stack<char>& s, int i)
{
	if (i >= str.size()) return 0;

	// discard case : do nothing
	int ret = cache[i];
	if (ret >= 0) return ret;
	ret = max(ret, matching(s, i+1));

	auto it = opening.find(str[i]);

	// opening
	if (it != string::npos)
	{
		s.push(str[i]);
		ret = max(ret, matching(s, i+1));
		s.pop();
	}
	else if (s.size() > 0) // closing
	{
		char c = s.top();
		if (closing.find(str[i]) == opening.find(c))
		{
			s.pop();
			ret = max(ret, matching(s, i+1)+2);
			s.push(c);
		}
	}
	return ret;
}

int main()
{
#ifdef _DEBUG
	freopen("brackets.in","r",stdin);
#endif
	
	cin >> str;
	while (str != "end")
	{
		memset(cache, -1, sizeof(cache));
		stack<char> s;
		cout << matching(s, 0) << endl;
		cin >> str;
	}

	return 0;
}

