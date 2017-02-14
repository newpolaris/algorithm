#include <iostream>
#include <string>
#include <string.h>
#include <iostream>
#include <regex>
#include <cassert>
#include <map>
#include <set>
#include <queue>

#define ALL(x) (x).begin(), (x).end()
#define forn(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define x first
#define y second

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("765d.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	vector<int> f(n+1);
	for (int i = 1; i <= n; i++)
		cin >> f[i];
	/*
	 * 이게 충분히 강한 조건 인가?
	 *
	 * h(g(x)) = (hg)(x) = f(x)
	 * <=> (hghg)(x) = f(f(x))
	 * <=> (h(gh)g)(x) = f(f(x))
	 * <=> (hg)(x) = f(f(x)) where (gh)(x) = x = (I)(x)
	 * <=> f(f(x)) = f(x)
	 */
	bool bExist = true;
	for (int i = 1; i <= n; i++) {
		if (f[i] <= n && f[f[i]] == f[i])
			continue;
		bExist = false;	
		break;
	}
	if (!bExist) {
		cout << -1 << endl;
		return 0;
	}

	// 0 부분 제거
	f.erase(f.begin());

	// 단순히 matching 찾기. 존재 조건은 위에걸로 커버된다고 생각

	// 중복 제거한게 h
	auto h = f;
	sort(ALL(h));
	h.erase(unique(ALL(h)), h.end());

	// 빠르게 찾기위해 map에 등록
	map<int, int> idxMap;
	forn (i, 0, h.size())
		idxMap[h[i]] = i;
	vector<int> g(n);
	// 원래는 f 인데 index를 멀로해야 되나?
	forn (i, 0, n) 
		g[i] = idxMap[f[i]] + 1; 
	cout << h.size() << endl;
	copy(ALL(g), ostream_iterator<int>(cout, " "));
	cout << endl;
	copy(ALL(h), ostream_iterator<int>(cout, " "));
	cout << endl;

	return 0;
}
