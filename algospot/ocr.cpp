#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include <string.h>
#include <math.h>

using namespace std;

typedef float FP;

int m, q, n;
vector<vector<FP>> M, T;
vector<FP> B;
vector<int> S;

const int MMax = 501;
const int QMax = 101;
FP cache[QMax][MMax];
int choose[QMax][MMax];

int INF = 987654321;

FP GetTP(int step, int i, int prev)
{
	FP Tt = (step == 0) ? B[i] : T[prev][i];
	FP Mt = M[i][S[step]];

	return Tt + Mt;
}

FP search(int step, int prev)
{
	if (step == n) return 0.0;
	FP& ret = cache[step][prev];
	if (ret < 1.0) return ret;	
	ret = -INF;
	for (int i = 0; i < m; i++)
	{
		FP Tp = GetTP(step, i, prev);
		if (Tp < -INF) continue;
		
		Tp += search(step+1, i);
		if (Tp > ret)
		{
			ret = Tp;
			choose[step][prev] = i;
		}
	}

	return ret;
}

string reconstruct(vector<string>& R, int prev, int step)
{
	if (step == S.size()) return "";
	int Next = choose[step][prev];
	return R[Next] + " " + reconstruct(R, Next, step+1);
}

char buf[11];
int main()
{
#if _DEBUG
	freopen("ocr.in", "r", stdin);
#endif
	FP dd;

	scanf("%d%d", &m, &q); 

	vector<string> R;
	for (int i = 0; i < m; i++)
	{
		scanf("%s", buf);
		R.push_back(buf);
	}

	B = vector<FP>(m);
	for (int c = 0; c < m; c++)
	{
		scanf("%f", &B[c]);
		B[c] = log10(B[c]);
	}

	T = vector<vector<FP>>(m, vector<FP>(m));
	for (int r = 0; r < m; r++)
	for (int c = 0; c < m; c++)
	{
		scanf("%f", &T[r][c]);
		T[r][c] = log10(T[r][c]);
	}

	M = vector<vector<FP>>(m, vector<FP>(m));
	for (int r = 0; r < m; r++)
	for (int c = 0; c < m; c++)
	{
		scanf("%f", &M[r][c]);
		M[r][c] = log10(M[r][c]);
	}

	while (q--)
	{
		for (int r = 0; r < MMax; r++)
		for (int c = 0; c < QMax; c++)
			cache[c][r] = 1.0;

		memset(&choose, -1, sizeof(choose));

		scanf("%d", &n);
		S.clear();
		for (int i = 0; i < n; i++)
		{
			scanf("%s", buf);
			auto it = find(R.begin(), R.end(), buf);
			S.push_back(distance(R.begin(), it));
		}

		search(0, 0);
		string sol = reconstruct(R, 0, 0);
		printf("%s\n", sol.c_str());
	}

	return 0;
}

