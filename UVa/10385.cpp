// Duathlon
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>

double R[20], K[20];

using namespace std;

int main()
{
#ifdef _DEBUG
	freopen("10385.in", "r", stdin);
#endif
	double t;
	while (cin >> t)
	{
		int n; 
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> R[i] >> K[i];

		auto time = [&](int i, double r)
		{
			auto k = t - r;	
			return r/R[i] + k/K[i];
		};
		auto f = [&](double r)
		{
			vector<double> D(n); 
			for (int i = 0; i < n; i++)
				D[i] = time(i, r);
			auto snd = *min_element(D.begin(), D.begin()+(n-1));
			return snd - D[n-1];
		};
		double lo = 0.0, hi = t;
		for (int i = 0; i < 100; i++)
		{
			double lT = (2*lo +hi)/3.0;		
			double rT = (lo + 2*hi)/3.0;
			if (f(lT) > f(rT))
				hi = rT;
			else
				lo = lT;
		}
		double sec = f(lo) * 3600.0;
		if (sec < 0)
			printf("The cheater cannot win.\n");
		else
			printf("The cheater can win by %.0lf seconds with r = %.2lfkm and k = %.2lfkm.\n", sec, lo, t-lo);
	}
	return 0;
}
