// Duathlon
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

float R[20], K[20];

using namespace std;

int main()
{
#ifdef _DEBUG
	freopen("10385.in", "r", stdin);
#endif
	float t;
	while (cin >> t)
	{
		int n; 
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> R[i] >> K[i];

		auto time = [&](int i, float r)
		{
			auto k = t - r;	
			return r/R[i] + k/K[i];
		};
		auto f = [&](float r)
		{
			vector<float> D(20); 
			for (int i = 0; i < n; i++)
				D[i] = time(i, r);
			auto snd = *max_element(D.begin(), D.begin()+(n-1));
			return snd - D[n-1];
		};
		float lo = 0.0, hi = 100.0;
		for (int i = 0; i < 100; i++)
		{
			float leftThird = lo + (hi - lo)/3.0;		
			float rightThird = hi - (hi - lo)/3.0;
			if (f(leftThird) > f(rightThird))
				lo = leftThird;
			else
				hi = rightThird;
		}
		float sec = f(lo);
		cout << fixed << setprecision(2);
		cout << sec << " " << lo << " " << hi << endl;
	}
	return 0;
}
