#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <cmath>

using namespace std;

inline double dist(double ax, double ay, double bx, double by)
{
	return sqrt((ax - bx)*(ax - bx) + (ay - by)*(ay - by));
}

int main()
{
#if _DEBUG
	ifstream fin("P671a.in");
	istream& in = fin;
#else
	istream& in = cin;
#endif

	int ax, ay, bx, by, tx, ty, n, x, y;
	in >> ax >> ay >> bx >> by >> tx >> ty;
	in >> n;

	vector<pair<double, int>> adil;
	vector<pair<double, int>> bera;

	double sum = 0.0;
	for (int i = 0; i < n; i++)
	{
		in >> x >> y;
		double d = dist(tx, ty, x, y);
		sum += d * 2;
		adil.emplace_back(dist(ax, ay, x, y) - d, i);
		bera.emplace_back(dist(bx, by, x, y) - d, i);
	}

	sort(adil.begin(), adil.end());
	sort(bera.begin(), bera.end());

	double minsum = sum;
	if (adil[0].second != bera[0].second)
		minsum += adil[0].first + bera[0].first;
	else
		minsum += min(adil[0].first + bera[1].first, adil[1].first + bera[0].first);

	minsum = min(minsum, min(sum + adil[0].first, sum + bera[0].first));

	cout << fixed << setprecision(15);
	cout << minsum << endl;

	return 0;
}
