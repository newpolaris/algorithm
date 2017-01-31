/*
  n개의 봉이 있습니다. 봉 i의 길이는 ai입니다.
  여러분은 3개의 봉을 선택해서 가능한 둘레의 길이가 긴 삼각형을 만들려고 합니다.
  둘레의 길이의 최대 값을 구하세요(만약 삼각형을 만들 수 없는 경우에는 0을 답합니다).
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

#define ALL(x) (x).begin(), (x).end()
#define REP(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define SZ(x) (int((x).size()))

using namespace std;

// alogirhtm: m - k3 - k4 = k1 + k2
int main() {
#ifdef _DEBUG
	freopen("triangle.in", "r", stdin);
#endif
	int c, n;
	cin >> c;
	while (c--) {
		cin >> n;
		vector<int> a(n);
		for (auto& i : a)
			cin >> i;
		sort(ALL(a));
		int roundLength = 0;
		for (int i = n-3; i >= 0; i--) {
			if (a[i+2] < a[i] + a[i+1]) {
				roundLength = a[i] + a[i+1] + a[i+2];
				break;
			}
		}
		cout << roundLength << endl;
	}
	return 0;
}
