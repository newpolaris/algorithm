#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> getPartialMatch(string& N)
{
	int n = N.size(); 
	vector<int> pi(n, 0);

	int begin = 1, matched = 0;
	// KMP 로 자기 자신을 찾는다.
	// N을 N에서 찾는다.
	while (begin + matched < n)
	{
		if (N[begin + matched] == N[matched])
		{
			matched++;
			pi[begin+matched-1] = matched;
		}
		else
		{
			if (matched == 0)
				begin++;
			else
			{
				begin += matched - pi[matched-1];
				matched = pi[matched-1];
			}
		}
	}

	return pi;
}

vector<int> kmpSearch(string& H, string& N)
{
	int h = H.size(), n = N.size();

	// pi[i] = N[:i-1] 의 접미사도 되고 접두사도 되는 문자열의 최대 길이
	vector<int> found, pi = getPartialMatch(N);

	// begin = matched = 0 에서부터 시작하자.
	int begin = 0, matched = 0;
	while (begin <= h - n)
	{
		// 만약 짚더미에서의 해당 글자가 바늘의 해당 글자와 같다면
		if (matched < n && H[begin + matched] == N[matched])
		{
			matched++;
			// 결과적으로 m글자가 모두 일치했다면 답에 추가한다
			if (matched == n) found.push_back(begin);
		}
		else
		{
			//에외:matched 가 0 인 경우에는 다음 칸에서부터 계속
			if (matched == 0)
				begin++;
			else
			{
				begin += matched - pi[matched-1];
				// begin을 옮겼다고 처음부터 다시 비교할 필요가 없다.
				// 옮긴 후에도 pi[matched-1]만큼은 항상 일치하기 때문이다.
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

