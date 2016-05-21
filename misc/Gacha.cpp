// 해당 수식 증명을 위한 것
// 5.5 / 3 에서 10만번했을 때 대략 100. 근처 값이 나온다
//
// 손으로 수식 푸는 건: infinite sum의 미분형이다.
// http://math.stackexchange.com/questions/647587/sum-of-a-power-series-n-xn
//
#include <iostream>
#include <random>
#include <vector>

using namespace std;

int main()
{
	int C;

	cin >> C;

	long long totalCost = 0;

	for (int c = 0; c < C; c++)
	{
		std::uniform_real_distribution<double> unif(0.0, 100.0);
		std::random_device rand_dev;
		std::mt19937 rand_engine(rand_dev());

		bool T[3] = {false,};
		int trial = 0;
		while (true)
		{
			trial++;
			double x = unif(rand_engine);
			// 쿠폰 컬랙션 3/1 + 3/2 + 3/3 = 5.5
			// 100 번 굴렸을 때 다모으게 하려면 5.5/100 으로 주면 됨
			// 동일하므로 5.5 / 100 * 100 (percent) / 3
			int t = (int)(x / (5.5 / 3.0));
			if (t < 3)
				T[t] = true;

			if (T[0] && T[1] && T[2])
				break;
		}
		totalCost += trial;
	}

	cout << (double)totalCost / C << endl;

	return 0;
}

