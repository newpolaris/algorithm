#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;

typedef long long ll;

int main()
{
#ifdef _DEBUG
	freopen("725c.in", "r", stdin);
#endif

	string s;
	cin >> s;
	vector<int> alpha(26);
	for (int i = 0; i < 26; i++) {
		alpha[i] = count(s.begin(), s.end(), ('A'+i));
	}
	copy(alpha.begin(), alpha.end(), ostream_iterator<int>(cout, " "));
	return 0;
}
