// lus6's code
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

int main()
{
	string words[] = { "c-", "c=", "dz=", "d-", "lj", "nj", "s=", "z=" };
	string input;
	int cnt = 0;
	cin >> input;

	for (int i = 0; i < input.size(); ++i, ++cnt)
	{
		for (int j = 0; j < 8; j++)
		{
			if (input.compare(i, words[j].size(), words[j]) == 0)
			{
				i += words[j].size() - 1;
			}
		}
	}

	cout << cnt << endl;
}
