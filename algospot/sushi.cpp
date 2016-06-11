#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

int N, Max, Min;

vector<int> Cost;
vector<int> Sati;
int cache[401];

int MaximumSati(int C)
{
	int& ret = cache[C];
	if (ret != 0) return ret;

	if (C < Min) return ret;

	for (int i = 0; i < N; i++)
		ret = max(ret, MaximumSati(C - Cost[i]) + Sati[i]);

	return ret;
}

int main()
{
#ifdef _DEBUG
	freopen("sushi.in", "r", stdin);
#endif
	
	int C;
	cin >> C;
	while (C--)
	{
		int M;
		cin >> N >> M;
		Cost = vector<int>(N);
		Sati = vector<int>(N);
		for (int i = 0; i < N; i++)
			cin >> Cost[i] >> Sati[i];
		for (auto& c : Cost) c /= 100;
		M /= 100;
		vector<double> Eff(N);
		for (int i = 0; i < N; i++)
			Eff[i] = (double)Sati[i]/Cost[i];
		int MaxI = distance(begin(Eff), max_element(begin(Eff), end(Eff)));
		Max = min(Cost[MaxI]*2, M);
		Min = *min_element(begin(Cost), end(Cost));

		int Change = Cost[MaxI]*2;
		int RemainM = M - Change;
		int BestSelect = RemainM/Cost[MaxI];
		int MaxSati = BestSelect * Cost[MaxI];

		memset(cache, 0, sizeof(cache));
		
		MaxSati += MaximumSati(Change);

		cout << MaxSati << endl;
	}

	return 0;
}
