#include <iostream>
#include <random>
#include <cmath>

using namespace std;

const int N = 24;
double dist[N][N];

int main()
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(1, 2000);
	vector<pair<int, int>> L;
	for (int n = 0; n < N; n++)
		L.push_back(make_pair(dis(gen), dis(gen)));

	cout << N << endl;
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			auto& d = dist[r][c];
			if (r == c) d = 0.0;
			else
			{
				auto a = L[r];
				auto b = L[c];
				auto dx = (a.first - b.first);
				auto dy = (a.second - b.second);
				d = sqrt((double)dx*dx + dy*dy);
			}
			cout << d << " ";
		}
		cout << endl;
	}

	return 0;
}
