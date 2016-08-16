#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int longest;

struct node
{
	bool contain(node& n) const
	{
		return pow(x - n.x, 2) + pow(y - n.y, 2) < pow(r - n.r, 2);
	}

	int maxdist(int m)
	{
		if (child.size() == 0)
			return 0;

		// 가장 큰 1, 2 개만 남긴다
		int m1 = 0, m2 = 0;
		for (auto &i : child)
		{
			// 현재까지의 길이는 자식 + 1. 이를 통해 추후 +1 해줄 필요가 없어짐
			m2 = max(m2, i->maxdist(m) + 1);
			if (m2 > m1) 
				swap(m1, m2);
		}
		longest = max(longest, m1 + m2);

		return m1;
	}

	// 큰 것대로 추가하여 가장 처음 찾은 node 가 직계 자손이다
	void addChild(node* n)
	{
		vector<int> inside;
		for (auto &i: child)
		{
			if (i->contain(*n))
			{
				i->addChild(n);
				return;
			}
		}
		// 자식의 자식이 아니라면 현 root 밑에 둔다
		child.push_back(n);
	}

	int x, y, r;
	vector<node*> child;
};

int main()
{
#ifdef _DEBUG
	freopen("fortress.in", "r", stdin);
#endif

	int n, c;

	cin >> n;

	while (n--)
	{
		cin >> c;

		vector<node> nodes(c);
		for (auto &e : nodes)
			cin >> e.x >> e.y >> e.r;

		sort(nodes.begin(), nodes.end(), 
			[](const node& a, const node& b)
				{ return a.r > b.r; });

		node* root = &nodes[0];
		for (int i = 1; i < nodes.size(); i++)
			root->addChild(&nodes[i]);

		int m = 0;
		longest = 0;
		root->maxdist(m);
		cout << longest << endl;
	}

	return 0;
}
