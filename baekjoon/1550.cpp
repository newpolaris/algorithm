#include <iostream>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	string s;
	cin >> s;
	cout << stoi(s, 0, 16) << endl;
	return 0;
}
