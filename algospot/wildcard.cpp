/*
in:
2
he?p
3
help
heap
helpp
*p*
3
help
papa
hello

output:
heap
help
help
papa
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <string.h>
#include <vector>

using namespace std;

int cache[101][101];

string s, w;

bool match(int sPos, int wPos)
{
	int& ret = cache[sPos][wPos];
	if (ret != -1)
		return ret;

	while (sPos < s.size() && wPos < w.size()
			&& (s[sPos] == w[wPos] || w[wPos] == '?'))
	{
		++wPos;
		++sPos;
	}

    if (wPos == w.size())
        return ret = (sPos == s.size());

    if (w[wPos] == '*')
        for (int skip = 0; skip+sPos <= s.size(); ++skip)
            if (match(sPos+skip, wPos+1))
                return ret = 1;
    return ret = 0;
}

int main()
{
    istream& in = cin;
    ostream& ot = cout;

    int C, K;
    in >> C;

    while (C--)
    {
        in >> w;
        in >> K;

		vector<string> q;
        while (K--)
        {
			memset(&cache, -1, sizeof(cache));

            in >> s;         
            if (match(0, 0))
				q.push_back(s);
        }
		sort(q.begin(), q.end());
		for_each(q.begin(), q.end(), [&](string s) { ot << s << endl;});
    }

    return 0;
}


