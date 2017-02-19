#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <vector>
#include <string.h>
#include <algorithm>
#include <numeric>
#include <regex>
#include <iterator>

using namespace std;

int main() {
#ifdef _DEBUG
#endif
	ios::sync_with_stdio(0);
	string k;
	getline(cin, k);
	char* str = (char*)(k.c_str());
	char* token = strtok(str, " ");
	int cnt = 0;
	while (token != nullptr) {
		cnt++;
		token = strtok(nullptr, " ");
	}
	cout << cnt << endl;

	return 0;
}
