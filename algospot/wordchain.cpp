#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <stack>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("wordchain.in", "r", stdin);
#endif

	int C, N;

	cin >> C;
	while (C--)
	{
		cin >> N;

		// 간선을 보관하기 위한 구조
		stack<pair<int, string*>> aj[26];

		int in[26] = { 0 }, ot[26] = { 0 };

		vector<string> str(N);
		for (auto &e : str)
		{
			cin >> e;
			int st = e.front() - 'a';
			int ed = e.back() - 'a';
			ot[st]++;
			in[ed]++;
			aj[st].push({ ed, &e });
		}

		/* 홀수 인 점 혹은 모두 짝수인 경우 짝수 인 임의의 점 정하기
		 * dog -> gooc : 
		 * ot['d'] = 1
		 * in['d'] = 0
		 * ot['g'] = 1
		 * in['g'] = 1
		 * ot['c'] = 0
		 * in['c'] = 1
		 */
		int s = -1;
		for (int i = 0; i < 26; i++)
			if (ot[i] != 0 && (s == -1 || in[i]+1 == ot[i]))
				s = i;

		vector<string*> sol;
		function<void(int)> eulercircuit = [&](int v) {
			while (!aj[v].empty()) {
				auto k = aj[v].top();
				aj[v].pop();

				eulercircuit(k.first);
				// 정점이 아닌 단어가 간선 이므로
				sol.push_back(k.second);
			}
		};

		eulercircuit(s);
		reverse(sol.begin(), sol.end());
		// 단어를 전부 사용한 경우
		bool bSuc = sol.size() == N;
		for (int i = 0; i < sol.size() - 1; i++) {
			if (sol[i]->back() != sol[i+1]->front())
				bSuc = false;
		}
		if (bSuc) {
			for (auto s : sol)
				cout << *s << " ";
			cout << endl;
		} else {
			cout << "IMPOSSIBLE" << endl;
		}
	}

	return 0;
}
