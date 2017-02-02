#include <iostream>
#include <vector>
#include <map>

#define x first
#define y second 

#define REP(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)

using namespace std;

struct rect {
	int a, b, c, d;
};

int main() {
#ifdef _DEBUG
	freopen("764d.in", "r", stdin);
#endif
	int n;
	cin >> n;
	vector<rect> rects(n);
	for (auto& r : rects) 
		cin >> r.a >> r.b >> r.c >> r.d;
	
}
