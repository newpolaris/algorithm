#include <iostream>
#include <map>

#define x first
#define y second

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("785a.in", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	map<string, int> poly = {
		{"Tetrahedron", 4},
		{"Cube", 6},
		{"Octahedron", 8},
		{"Dodecahedron", 12},
		{"Icosahedron", 20},
	};
	int n;
	cin >> n;
	int cnt = 0;
	string str;
	while (n--) {
		cin >> str;
		cnt += poly[str];
	}
	cout << cnt << endl;
		
	return 0;
}
