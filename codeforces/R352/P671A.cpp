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

#define DIST(ax, ay, bx, by) 
int main()
{
#if _DEBUG
	ifstream fin("P671A.in");
	istream& in = fin;
#else
	istream& in = cin;
#endif

	int ax, ay, bx, by, tx, ty, n, x, y;
	in >> ax >> ay >> bx >> by >> tx >> ty;
	in >> n;

	vector<double> trashbin(n);
	vector<pair<double, int>> adil(n);
	vector<pair<double, int>> bera(n);

	for (int i = 0; i < n; i++)
	{
		in >> x >> y;
		trashbin[i] = dist(tx, ty, x, y);
		adil[i] = { trashbin[i] - dist(ax, ay, x, y), i };
		bera[i] = { trashbin[i] - dist(bx, by, x, y), i };
	}

	double sum = accumulate(trashbin.begin(), trashbin.end(), 0.0) * 2;

	sort(adil.begin(), adil.end(), greater<pair<double, int>>());
	sort(bera.begin(), bera.end(), greater<pair<double, int>>());

	double minsum = min(sum-adil[0].first, sum-bera[0].first);
	if (adil[0].second == bera[0].second)
	{
		minsum = min(minsum, sum - adil[0].first - bera[1].first);
		minsum = min(minsum, sum - adil[1].first - bera[0].first);
	}
	else
	{
		minsum = min(minsum, sum - adil[0].first - bera[0].first);
	}

	cout << fixed << setprecision(15);
	cout << minsum << endl;

	return 0;
}
