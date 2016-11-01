#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;
struct node {
	node () : cnt(0), cost(0) {}
	bool contain(node& n) const {
		return pow(x - n.x, 2) + pow(y - n.y, 2) < pow(r - n.r, 2);
	}

	bool contain(ll x, ll y) const {
		return pow(x - x, 2) + pow(y - y, 2) < pow(r, 2);
	}

	void dfs() {
		for (int i = 0; i < child.size(); i++) {
			child[i]->dfs();
			cnt += child[i]->cnt;
			cost += child[i]->cost;
		}
		cost += cnt * c;
	}

	/*
	int maxdist(int m) {
		if (child.size() == 0)
			return 0;

		 가장 큰 1, 2 개만 남긴다
//                int m1 = 0, m2 = 0;
//                for (auto &i : child)
//                {
			 현재까지의 길이는 자식 + 1. 이를 통해 추후 +1 해줄 필요가 없어짐
//                        m2 = max(m2, i->maxdist(m) + 1);
//                        if (m2 > m1) 
//                                swap(m1, m2);
//                }
//                longest = max(longest, m1 + m2);

//                return m1;
//
//        }
//        */

	void addPeople(ll x, ll y) {
		for (auto &i: child) {
			if (i->contain(x, y))
			{
				i->addPeople(x, y);
				return;
			}
		}
		cnt++;
	}

	void addChild(node* n) {
		for (auto &i: child) {
			if (i->contain(*n))
			{
				i->addChild(n);
				return;
			}
		}
		child.push_back(n);
	}

	ll x, y, r, c, cnt, cost;
	vector<node*> child;
};

int main()
{
#ifdef _DEBUG
	freopen("f.in", "r", stdin);
#endif

	int n, q, m, x, y;
	cin >> n;

	vector<node> nodes(n);
	for (auto &e : nodes)
		cin >> e.x >> e.y >> e.r >> e.c;
	cin >> q;
	vector<pair<int, int>> pl;
	while (q--) {
		cin >> m;
		while (m--) {
			cin >> x >> y;
			pl.push_back({x, y});
		}
	}
	
	node big;
	big.x = 0, big.y = 0, big.r = 100000000, big.c = 0;

	sort(nodes.begin(), nodes.end(), 
			[](const node& a, const node& b)
			{ return a.r > b.r; });

	for (int i = 0; i < nodes.size(); i++)
		big.addChild(&nodes[i]);

	for (int i = 0; i < pl.size(); i++)
		big.addPeople(pl[i].first, pl[i].second);


	big.
//        int m = 0;
//        longest = 0;
//        root->maxdist(m);
//        cout << longest << endl;

	return 0;
}
