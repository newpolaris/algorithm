#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

struct point
{
	double x, y;
};

typedef pair<point, point> pp;
typedef vector<pp> vpp;

int main()
{
#ifdef _DEBUG
	freopen("fossile.in", "r", stdin);
#endif
	
	int C, N, M;
	cin >> C;
	while (C--)
	{
		cin >> N >> M;

		vector<point> hull[2];
		hull[0].resize(N);
		hull[1].resize(M);
		for (auto& h : hull[0])
			cin >> h.x >> h.y;
		for (auto& h : hull[1])
			cin >> h.x >> h.y;

		vpp upper, lower;

		auto decompose = [&upper, &lower](const vector<point>& hull) {
			int n = hull.size();
			// divide into upper, lower hull 
			for (int i = 0; i < n; i++) {
				auto& a = hull[i];
				auto& b = hull[(i+1)%n];
				if (a.x > b.x)
					upper.push_back({ a, b });
				else if (a.x < b.x)
					lower.push_back({ a, b });
			}
		};
		decompose(hull[0]);
		decompose(hull[1]);

		auto inside = [&](const point& p, const point& q, double x) {
			return (p.x <= x && x <= q.x) || (q.x <= x && x <= p.x);
		};

		auto at = [](const point& p, const point& q, double x) {
			double dy = q.y - p.y, dx = q.x - p.x;
			return p.y + dy * (x - p.x) / dx;
		};

		auto vertical = [&](double x)
		{
			double minY = 1e20;
			for (auto& u : upper)
				if (inside(u.first, u.second, x))
					minY = min(minY, at(u.first, u.second, x));

			int ln = lower.size();
			double maxY = -1e20;
			for (auto& l : lower)
			{
				if (inside(l.first, l.second, x))
					maxY = max(maxY, at(l.first, l.second, x));
			}
			return minY - maxY;
		};

		// solve
		auto minX = [](const vector<point>& p)
		{
			double v = 1e20;
			for (auto i = 0U; i < p.size(); i++)
				v = min(v, p[i].x);
			return v;
		};

		auto maxX = [](const vector<point>& p)
		{
			double v = -1e20;
			for (auto i = 0U; i < p.size(); i++)
				v = max(v, p[i].x);
			return v;
		};

		auto lo = max(minX(hull[0]), minX(hull[1]));
		auto hi = min(maxX(hull[0]), maxX(hull[1]));

		if (lo > hi)
		{
			cout << 0 << endl;
			continue;
		}

		for (int iter = 0; iter < 100; iter++)
		{
			auto a = (lo*2.0 + hi)/3.0;
			auto b = (lo + hi*2.0)/3.0;
			if (vertical(a) < vertical(b))
				lo = a;
			else
				hi = b;
		}

		cout << fixed << setprecision(10);
		cout << max(0.0, vertical(lo)) << endl;
	}
	return 0;
}

