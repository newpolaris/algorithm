#include <fstream>
#include <algorithm>
#include <functional>
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <string.h>
#include <queue>

using namespace std;

int main()
{
#if NDEBUG
	ifstream fin("A-small-attempt0.in");
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
		int N;
        in >> N;

		typedef pair<int, char> Pair;
		priority_queue<Pair, vector<Pair>, less<Pair>> queue;

		int P;
		for (int i = 0; i < N; i++)
		{
			in >> P;
			queue.push({ P, 'A'+i });
		}

		vector<string> sol;
		while (queue.size() > 2)
		{
			auto p = queue.top();
			queue.pop();
			sol.push_back(string(1, p.second));
			p.first--;
			if (p.first > 0)
				queue.push(p);
		}

		vector<Pair> vec;
		vec.push_back(queue.top());
		queue.pop();
		vec.push_back(queue.top());

		while (true)
		{
			if (vec[0].first == 0 && vec[1].first == 0)
				break;

			if (vec[0].first > vec[1].first)
			{
				sol.push_back(string(1, vec[0].second));
				vec[0].first--;
			}
			else if (vec[0].first < vec[1].first)
			{
				sol.push_back(string(1, vec[1].second));
				vec[1].first--;
			}
			else
			{
				string s;
				s += vec[0].second;
				s += vec[1].second;
				sol.push_back(s);
				vec[0].first--;
				vec[1].first--;
			}
		}

		ot << "Case #" << t << ": ";
		for (int i = 0; i < sol.size(); i++)
			ot << sol[i] << " ";
		ot << endl;
    }
    return 0;
}
