#include <iostream>
#include <string>
using namespace std;
int main() {
	string str;
	cin >> str;
	int s = 10;
	for (int i = 1; i < str.size(); i++)
		s += (str[i] == str[i-1]) ? 5 : 10;
	cout << s << endl;
	return 0;
}
