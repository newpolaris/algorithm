#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <iterator>
#include <string>
#include <regex>

using namespace std;

int maxcount(vector<string>& arr)
{
	int maxC = 0;
	regex re("_");
	for (auto& input : arr) {
		sregex_token_iterator first{input.begin(), input.end(), re, -1}, last;
		vector<string> word(first, last);
		for (auto& i : word)
			maxC = max(maxC, (int)i.size());
	}
	return maxC;
}

int numcount(vector<string>& arr)
{
	int maxC = 0;
	regex re("_");
	for (auto& input : arr) {
		sregex_token_iterator first{input.begin(), input.end(), re, -1}, last;
		vector<string> word(first, last);
		for (int i = 0; i < word.size(); i++)
			if (!word[i].empty())
				maxC++;
	}
	return maxC;
}


int main()
{
#ifdef _DEBUG
	freopen("723b.in", "r", stdin);
#endif

	int n, start = 0, end = -1;
	cin >> n;
	string s;
	cin >> s;
	vector<string> in, out;
	for (int i = 0; i < s.size(); i++) {
		if ('(' == s[i]) {
			out.push_back(s.substr(start, i - start));
			start = i+1;
		}
		else if (')' == s[i]) {
			in.push_back(s.substr(start, i - start));
			start = i+1;
		}
	}
	cout << maxcount(out) << " " << numcount(in) << endl;

	return 0;
}

