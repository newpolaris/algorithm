#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#pragma warning(disable:4996)

using namespace std;

inline void input(int& i)
{
#if _DEBUG
	static ifstream file("homuraarsenal.in");
	static istream& in = file;
	in >> i;
#else
	scanf("%d", &i);
#endif
}

int main()
{
	int r, n, k;

	input(r);

	while (r--)
	{
		input(n);
		input(k);

		vector<int> c(n);
		for (auto &e: c)
			input(e);

		int count = 0;

		int sI = 0;
		while (sI < n)
		{
			multiset<int> map;

			int hold = 0;
			int cc = 1;
			int partial = 1;
			int nextsI = 0;
			int eI = 0;

			for (eI = sI; eI < n; eI++)
			{
				int key = c[eI];

				if (map.end() == map.find(key))
				{
					map.insert(key);
					partial *= cc;
					cc = 1;
					hold++;
					if (map.size() == 2)
						nextsI = eI;
				}
				else
				{
					cc++;
				}
			
				if (hold > k)
				{
					count += partial;
					break;
				}
			}

			if (eI == n)
			{
				if (hold == k)
					count += partial;
				break;
			}

			sI = nextsI;
		}

		cout << count << endl;
	}
}
