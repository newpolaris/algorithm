#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>

using namespace std;

typedef vector<double> vd;
typedef const vd cvd;

vd differentiate(cvd& poly)
{
	vd v;
	int n = poly.size() - 1;
	for (int i = 0; i + 1 < poly.size(); i++)
		v.push_back(poly[i] * (n-i));

	return v;
}

vd solveNaive(cvd& poly)
{
	vd v;
	int n = poly.size() - 1;
	if (n == 1)
	{
		v.push_back(-poly[1] / poly[0]);
	}
	else if (n == 2)
	{
		double a = poly[0], b = poly[1], c = poly[2];
		double K = b*b - 4*a*c;
		if (K < 1e-9)
		{
			v.push_back(-b/2/a);
		}
		else
		{
			auto t = sqrt(K);
			v.push_back( (-b+t)/2/a );
			v.push_back( (-b-t)/2/a );
		}
	}
	sort(v.begin(), v.end());
	return v;
}

double evaluate(cvd& poly, double x0)
{
	int n = poly.size() - 1;
	double sum = 0.0;
	for (int i = 0; i < poly.size(); i++)
		sum += poly[i]*pow(x0, n-i);
	return sum;
}

const double L = 25;

vd solve(cvd& poly)
{
	int n = poly.size() - 1;
	if (n <= 2) return solveNaive(poly);

	vd derivative = differentiate(poly);
	vd sols = solve(derivative);

	sols.insert(sols.begin(), -L-1);
	sols.insert(sols.end(), L+1);

	vd ret;
	for (int i = 0; i+1 < sols.size(); ++i)
	{
		double x1 =sols[i], x2 = sols[i+1];
		double y1 = evaluate(poly, x1), y2 = evaluate(poly, x2);
		if (y1 * y2 > 0) continue;
		if (y1 > y2) { swap(y1, y2), swap(x1, x2); }
		for (int iter = 0; iter < 100; ++iter)
		{
			double mx = (x1 + x2)/2;
			double my = evaluate(poly, mx);
			if (y1*my > 0) {
				y1 = my;
				x1 = mx;
			}
			else {
				y2 = my;
				x2 = mx;
			}
		}
		ret.push_back((x1 + x2)/2);
	}
	sort(ret.begin(), ret.end());
	return ret;
}

int main()
{
#ifdef _DEBUG
	freopen("roots.in", "r", stdin);
#endif
	int C, N;
	cin >> C;
	while (C--)
	{
		cin >> N;
		vd v(N+1);
		for (auto &a : v)
			cin >> a;
		auto sols = solve(v);
		cout << fixed << setprecision(9);
		for (auto &s : sols)
			cout << s << " ";
		cout << endl;
	}
	return 0;
}

