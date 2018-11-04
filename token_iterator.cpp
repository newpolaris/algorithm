// http://www.informit.com/articles/article.aspx?p=2064649&seqNum=7
// http://stackoverflow.com/questions/9435385/split-a-string-using-c11
#include <iostream>
#include <regex>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string.h>

using namespace std;

vector<string> split(const string& input, const string& reText) {
	regex re(reText);
	sregex_token_iterator first{input.begin(), input.end(), re, 0}, last;
	return {first, last};
}

int main()
{
	auto text = string(" hello world, hi every one");
	auto delimiters = string("[^\\s,]+");
	auto arr = split(text, delimiters);
	if (arr.size() > 0 && arr[0].empty()) arr.erase(arr.begin());
	copy(begin(arr), end(arr), ostream_iterator<string>(cout, "\n"));

	char* str = (char*)(text.c_str());
	char* token = strtok(str, " ,.-");
	while (token != nullptr) {
		cout << string(token) << endl;
		token = strtok(nullptr, " ,.-");
	}

	return 0;
}
