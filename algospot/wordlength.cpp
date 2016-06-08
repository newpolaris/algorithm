#include <vector>
#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
#include <memory>
#include <cctype>

using namespace std;

int main()
{
#ifdef _DEBUG
	freopen("wordlength.in", "r", stdin);
#endif

	int T, N;
	cin >> T;
	while (T--) {
		cin >> N;
		string oneline, str;
		getline(cin, str);
		while (N--) {
			getline(cin, str);
			int s = oneline.size();
			if (s > 1 && oneline[s-1] == '-' && isalpha(oneline[s-2]) && isalpha(str[0]))
				oneline.pop_back();
			else
				oneline += " ";
			oneline += str;
		}

		vector<string> words;
		char* chr = (char*)(oneline.c_str());
		char* token = strtok(chr, " -.,");
		while (token != NULL) {
			words.push_back(string(token));
			token = strtok(NULL, " -.,");
		}
		int sum = 0;
		for (auto& k : words)
			sum += k.size();
		cout << fixed << setprecision(3);
		cout << ((double)sum/words.size()) << endl;
	}
}

