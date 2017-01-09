#include <iostream>
#include <math.h>

using namespace std;

int main() {
	freopen("qa.in2", "r", stdin);
#ifndef _DEBUG
	freopen("qa.out2", "w", stdout);
#endif
	int T;
	double P, X, Y;
	cin >> T;
	const double twopi = acos(0.0)*4;
	for (int i = 1; i <= T; i++) { 
		cin >> P >> X >> Y;
		X -= 50; Y -= 50;
		double angle = atan2(Y, X)-atan2(50, 0);
		double progress = fmod(twopi-angle, twopi) / twopi * 100;
		cout << "Case #" << i << ": " 
			<< ((X*X+Y*Y <= 50*50 && progress <= P) ? "black" : "white") 
			<< endl;
	}

	return 0;
}
