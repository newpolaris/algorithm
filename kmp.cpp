#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> getPartialMatch(string& N)
{
	int n = N.size(); 
	// KMP 로 자기 자신을 찾는다.
	// N을 N에서 찾는다.
	vector<int> pi(n, 0);
	int matched = 0;
	for (int i = 1; i < n; i++)
	{
		while (matched > 0 && N[i] != N[matched])
			matched = pi[matched-1];
		if (N[i] == N[matched]) matched++;
		pi[i] = matched;
	}
	return pi;
}

vector<int> kmpSearch(string& H, string& N)
{
	int h = H.size(), n = N.size();

	// pi[i] = N[:i-1] 의 접미사도 되고 접두사도 되는 문자열의 최대 길이
	vector<int> found, pi = getPartialMatch(N);

	// i = 0 에서부터 시작하자.
	int matched = 0;
	for (int i = 0; i < h; i++) {
		// matched 번 글자와 짚더미의 해당 글자가 불일치할 경우,
		// 현재 대응된 글자의 수를 pi[matched-1]로 줄인다.
		while (matched > 0 && H[i] != N[matched])
			matched = pi[matched-1];
		// 글자가 대응될 경우
		if (H[i] == N[matched]) {
			++matched;
			if (matched == n) {
				found.push_back(i - n + 1);
				matched = pi[matched-1];
			}
		}
	}
	return found;
}

int main()
{
#ifdef _DEBUG
	freopen("naming.in", "r", stdin);
#endif
	
	//          01234567890123456
	string H = "aaaabaabaaabaabac";
	string N = "aabaabac";

	auto k = kmpSearch(H, N);
	
	for (auto a : k)
		cout << a << " ";

	return 0;
}

