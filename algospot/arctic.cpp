#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

float W[100][100];
float xs[100], ys[100];

float prim(int numLab)
{
	vector<float> distance(numLab, numeric_limits<float>::infinity());
	vector<bool> checked(numLab, false);

	distance[0] = 0; 

	int n = numLab;
	while (n--)
	{
		float minDist = numeric_limits<float>::infinity();

		int vnear = -1; // next cadidate vertex
		for (int i = 0; i < numLab; i++)
		{
			if (!checked[i] && distance[i] < minDist)
			{
				vnear = i;
				minDist = distance[i];
			}
		}

		checked[vnear] = true;
		for (int i = 0; i < numLab; i++)
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

	int numTest;
	cin >> numTest;

	while (numTest--)
	{
		int numLab;
		cin >> numLab;

		for (int i = 0; i < numLab; i++)
			cin >> xs[i] >> ys[i];

		for (int i = 0; i < numLab; i++)
		{
			W[i][i] = 0;
			for (int j = i + 1; j < numLab; j++)
			{
				double dx = xs[j] - xs[i];
				double dy = ys[j] - ys[i];
				W[j][i] = W[i][j] = dx*dx + dy*dy;
			}
		}

		printf("%.2f\n", round(sqrt(prim(numLab)) * 100) / 100);
	}

	return 0;
}
