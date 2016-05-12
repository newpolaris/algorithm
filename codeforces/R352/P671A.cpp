#include <algorithm>
#include <cmath>
#include <functional>
#include <tuple>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip> 

using namespace std;

vector<pair<int, int>> T;

vector<double> getDist(int ax, int ay)
{
	vector<double> aa(T.size());
	for (int i = 0; i < T.size(); i++)
	{
		double d = 0;
		d += (double)(T[i].first - ax)*(T[i].first - ax);
		d += (double)(T[i].second- ay)*(T[i].second- ay);
		aa[i] = sqrt(d);
	}
	return aa;
}

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

	T = vector<pair<int, int>>(n);
	for (auto& t : T)
		in >> t.first >> t.second;

	vector<double> dist = getDist(tx, ty);
	vector<double> aa = getDist(ax, ay);
	vector<double> bb = getDist(bx, by);

	vector<tuple<double, int, int>> z;
	for (int i = 0; i < aa.size(); i++)
		z.push_back(make_tuple(dist[i]-aa[i], i, 0));

	for (int i = 0; i < bb.size(); i++)
		z.push_back(make_tuple(dist[i]-bb[i], i, 1));

	sort(z.begin(), z.end(), greater<tuple<double, int, int>>());
	int code = get<2>(z[0]);
	int sel = get<1>(z[0]);
	int sec;
	for (sec = 0; sec < z.size(); sec++)
	{
		if (get<2>(z[sec]) != code && get<1>(z[sec]) != sel)
			break;
	}

	double sum = 0;
	for (int i = 0; i < dist.size(); i++)
		sum += dist[i]*2;

	double d0 = get<0>(z[0]);
	double d1 = get<0>(z[sec]);

	sum -= d0;
	if (d1 > 0)
		sum -= d1;
	cout << fixed << setprecision(15);
	cout << sum << endl;
	return 0;
}

