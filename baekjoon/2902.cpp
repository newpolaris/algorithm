#include <iostream>
#include <string>
#include <iterator>
#include <regex>

using namespace std;

vector<string> split(const string& a, const string& b) {
	regex re(b);
	sregex_token_iterator s{a.begin(), a.end(), re, 0}, e;
	return {s, e};
}

int main() {
	ios::sync_with_stdio(0);
	string str;
	cin >> str;
	auto tk = split(str, "[^-]+");
	for (auto& t : tk) {
		cout << t[0];
	}
	cout << endl;

	return 0;
}
