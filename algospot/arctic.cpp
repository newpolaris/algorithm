#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

float W[100][100];
float xs[100], ys[100];

float prim(int N)
{
	vector<float> distance(N, 1e200);
	vector<bool> checked(N, false);

	distance[0] = 0.f; 

	int n = N;
	while (n--)
	{
		float minDist = 1e200;

		int vnear = -1; // next cadidate vertex
		for (int i = 0; i < N; i++)
		{
			if (!checked[i] && distance[i] < minDist)
			{
				vnear = i;
				minDist = distance[i];
			}
		}

		checked[vnear] = true;
		for (int i = 0; i < N; i++)
		{
			if (!checked[i] && W[vnear][i] < distance[i])
				distance[i] = W[vnear][i];
		}
	}

	return *max_element(distance.begin(), distance.end());
}

int main()
{
#ifdef _DEBUG
	freopen("arctic.in", "r", stdin);
#endif

	int C;
	cin >> C;

	while (C--)
	{
		int N;
		cin >> N;

		for (int i = 0; i < N; i++)
			cin >> xs[i] >> ys[i];

		for (int i = 0; i < N; i++)
		{
			W[i][i] = 0;
			for (int j = i + 1; j < N; j++)
			{
				float dx = xs[j] - xs[i], dy = ys[j] - ys[i];
				W[j][i] = W[i][j] = dx*dx + dy*dy;
			}
		}

		printf("%.2f\n", sqrt(prim(N)));
	}

	return 0;
}
