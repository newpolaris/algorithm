#include <iostream>
#include <string>
#include <algorithm>
#include <string.h>

using namespace std;

string str;
const string opening = "([", closing = ")]";
int cache[101][101];

// 닫는 괄호는 무시하고, 열린기호에서 모든 닫는 기호에 대해 처리한다.
// 핵심은 cache를 2중으로 from, to 로 두는 것
int match(int from, int to)
{
	if (from >= to) return 0;
	if (cache[from][to] >= 0) return cache[from][to];

	int& ret = cache[from][to];
	ret = 0;
	auto io = opening.find(str[from]);
	if (io != string::npos)
	{
		int start = from+1;
		while (true)
		{
			int lc = -1;
			for (int i = start; i <= to; i++) 
			{
				if (str[i] == closing[io]) 
				{
					lc = i; break;
				}
			}
			if (lc == -1) break;
			ret = max(ret, match(from+1, lc-1) + 2 + match(lc+1, to));
			start = lc + 1;
		}
	}
	// opening skip case & closing
	ret = max(ret, match(from+1, to));

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
		cout << match(0, str.size()) << endl;
		cin >> str;
	}

	return 0;
}

