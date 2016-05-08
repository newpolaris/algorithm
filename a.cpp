#include <fstream>
#include <iostream>
#include <set>
#include <vector>
#include <string.h>
#include <queue>

using namespace std;

typedef __int64_t ll;

int main()
{
#if NDEBUG
	ifstream fin("input.txt");
	ofstream fout("out.txt");

	istream& in = fin;
	ostream& ot = fout;
#else
	istream& in = cin;
	ostream& ot = cout;
#endif

    int T;
    in >> T;

    for (int t = 1; t <= T; t++)
    {
		int B, M;
        in >> B >> M;

		vector<int> List(20, 0);
		List[0] = 1;

		int b = 0;
		int TM = M;

		vector<vector<int>> AL(B);

		while (b < B)
		{
			int sum = 0;
			for (int i = b - 1; i >= 0; --i)	
			{
				if (TM - List[i] > 0)
				{
					AL[b].push_back(i);
					sum += List[i];
					TM -= List[i];
				}
			}
			List[b] = sum;
		}

		if (TM > 0)
		{
		}

		ot << "Case #" << t << ": ";
		for (int i = 0; i < sol.size(); i++)
			ot << sol[i] << " ";
		ot << endl;
    }
    return 0;
}
