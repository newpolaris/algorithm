#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
#ifdef _DEBUG
	freopen("loan.in", "r", stdin);
#endif
	int C;
	double N, M, P;
	cin >> C;
	while (C--)
	{
		cin >> N >> M >> P;
		double r = 1.0 + P/1200.0;	
		double S =  N * (r - 1.0) * pow(r, M) / (pow(r, M) - 1);
		cout << fixed << setprecision(8);
		cout << S << endl;
	}

	return 0;
}

