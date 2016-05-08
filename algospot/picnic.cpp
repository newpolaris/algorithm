#include <iostream>
#include <assert.h>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <string.h>

using namespace std;

int List[10][10];

int EMPTY = -1;
int paring(vector<bool>& used, int next)
{
	int idx = EMPTY;
	for (int i = next; i < used.size(); i++)
	{
		if (!used[i])
		{
			idx = i;
			break;
		}
	}
	if (idx == EMPTY)
		return 1;

	int ret = 0;
	for (int i = idx + 1; i < 10; i++)
	{
		if (List[idx][i] && !used[i])
		{
			used[idx] = used[i] = true;
			ret += paring(used, idx + 1);
			used[idx] = used[i] = false;
		}
	}

	return ret;
}

int main()
{
	istream& in = cin;

	int C, a, b;
	in >> C;

	while (C--)
	{
		int N, M;
		in >> N >> M;

		memset(&List, 0, sizeof(List));

		for (int i = 0; i < M; i++)
		{
			in >> a >> b;
			List[a][b] = 1;
			List[b][a] = 1;
		}

		auto used = vector<bool>(N);
		cout << paring(used, 0) << endl;
	}

	return 0;
}
