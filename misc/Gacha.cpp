// 해당 수식 증명을 위한 것
// 5.5 / 3 에서 10만번했을 때 대략 100. 근처 값이 나온다
//
// 손으로 수식 푸는 건: infinite sum의 미분형이다.
// http://math.stackexchange.com/questions/647587/sum-of-a-power-series-n-xn
//
// 확률 자체가 A,B,C 그룹만이 존재했을 때를 가정으로 풀었는데 거기에
// 꽝이 나올 확률 즉 임의의 화률 높은 D 가 추가됬을 때도 성립한다는게 놀랍다.
//
// Let T be the time to collect all n coupons, and let ti be the time to collect 
// the i-th coupon after i − 1 coupons have been collected. Think of T and ti as
// random variables. Observe that the probability of collecting a new coupon is 
// pi = (n − (i − 1))/n. Therefore, ti has geometric distribution with expectation 1/pi. 
// By the linearity of expectations we have:
//
// 집합을 둘로 나눠 각각의 성공 실패로 나눈다. a, b 집합으로 나눴을 때 a에 A,B,C가 
// 속한다고 치고 a 가 5.5 번 선택될 경우 평균적으로 A,B,C 모두 선택됨
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
			int t = (int)(x / (5.5 / 100 * 100 / 3.0));
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

