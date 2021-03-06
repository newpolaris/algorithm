#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
typedef vector<int> vi;

const int maxN = 8;
int dist[40320]; // maxN! (8!)

// map<vector<int>, int> 를 쓰지 않고 특정 배열에 해당하는perm 을 계산하여
// 그 perm 을 dist 에서 할당하게 하여 map access 속도를 제거한다.
int perm(const vi& in)
{
	int index = 0;
	int position = 1;
	int factor = 1;
	for (int i = in.size() - 2; i >= 0; i--)
	{
		int count = 0;
		for (int k = i + 1; k < in.size(); k++)
			if (in[i] > in[k])
				count++;
		index += count*factor;
		factor *= ++position;
	}
	return index;
}

void precalc()
{
	memset(dist, -1, sizeof(dist));
	dist[0] = 0;

	vector<int> S(maxN);
	for (int i = 0; i < S.size(); i++) 
		S[i] = i;

	queue<vi> q;
	q.push(S);

	while (!q.empty())
	{
		auto here = q.front();
		q.pop();

		int idxHere = perm(here);
		for (int i = 0; i < maxN; i++)
		{
			for (int j = i+2; j <= maxN; j++)
			{
				// reverse 두 개 쌍은 perm을 취하고 무효화 하기 위한 것으로
				// reverse 를 직접 행하는게 save and restore 보다 빠르다
				reverse(here.begin()+i, here.begin()+j);
				int idxThere = perm(here);
				if (dist[idxThere] == -1)
				{
					dist[idxThere] = dist[idxHere]+1;
					q.push(here);
				}
				reverse(here.begin()+i, here.begin()+j);
			}
		}
	}
}

int solve(const vi& L)
{
	int N = L.size();
	vector<pair<int,int>> pi;
	for (int i = 0; i < N; i++)
		pi.push_back({L[i], i});
	sort(pi.begin(), pi.end());

	vector<int> ans(maxN);
	for (int i = 0; i < ans.size(); i++) 
		ans[i] = i;
	for (int i = 0; i < N; i++)
		ans[i] = pi[i].second;

	return dist[perm(ans)];
}

int main()
{
#ifdef _DEBUG
	freopen("sortgame.in", "r", stdin);
#endif

	int C, N;
	cin >> C;
	precalc();

	while (C--)
	{
		cin >> N;
		vi L(N);
		for (auto& l : L)
			cin >> l;
		cout << solve(L) << endl;
	}

	return 0;
}

