#include <iostream>
#include <math.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("qa.in", "r", stdin);
	// freopen("qa.out", "w", stdout);
#endif
	int T;
	double P, X, Y;
	cin >> T;
	const double pi = acos(0.0)*2;
	for (int i = 1; i <= T; i++) { 
		cin >> P >> X >> Y;
		X -= 50; Y -= 50;
		double deg = (atan2(Y, X)/pi*180);
		double progress = fmod(360-deg+90, 360) / 3.60;
		cout << "Case #" << i << ": " 
			<< ((X*X+Y*Y <= 50*50 && progress <= P) ? "black" : "white") 
			<< endl;
	}

	return 0;
}
