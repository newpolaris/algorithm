#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

typedef vector<int> vi;
int n, r;

bool next_comb(vi& v)
{
	// 1. Find the largest i such that ai != n - r + i
	int i = r;
	while (v[i - 1] == n - r + i)
		i--;
	i--;
	if (i >= r || i < 0)
		return false;
	v[i] += 1;
	for (int j = i + 1; j < r; j++)
		v[j] = v[j - 1] + 1;

	return true;
}

template <typename T>
ostream& operator<< (ostream& out, const vector<T>& v) {
	if (!v.empty()) {
		copy(v.begin(), v.end(), ostream_iterator<T>(out, ", "));
	}
	return out;
}

int main()
{
	n = 5, r = 3;
	vi v(r);
	iota(begin(v), end(v), 1);

	do
	{
		cout << v << endl;
	}
	while (next_comb(v));

	return 0;
}
