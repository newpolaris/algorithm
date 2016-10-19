#include <iostream>
#include <vector>
#include <string>
#include <regex>
#include <iterator>
#include <memory>

using namespace std;

const int ALPHABET = 26;

struct TrieNode; 
using TrieNodePtr = shared_ptr<TrieNode>;

int GetKey(char ch) { return ch - 'A'; }

struct TrieNode {
	int terminal = -1;
	int first = -1;
	TrieNodePtr child[ALPHABET];

	TrieNode() {}
	~TrieNode() {}
	void insert(const char* key, int idx) {
		if (first == -1) first = idx;
		if (*key == 0) {
			terminal = idx;
		} else {
			auto i = GetKey(*key);
			if (child[i] == nullptr)
				child[i] = make_shared<TrieNode>();
			child[i]->insert(key + 1, idx);
		}
	}
	TrieNode* find(const char* word) {
		if (*word == 0) {
			if (terminal != -1)
				return this;
			return nullptr;
		}
		auto i = GetKey(*word);
		if (child[i] == nullptr) 
			return nullptr;
		return child[i]->find(word+1);
	}
	// 이 노드까지 타이핑해 왔을 때, 번호 id인 key를 타이핑하기 위해
	// 최소 몇 번의 키를 더 눌러야 하나?
	int type(const char* key, int id) {
		if (*key == 0) return 0;
		if (first == id) return 1;
		auto i = GetKey(*key);
		return 1 + child[i]->type(key + 1, id);
	}
};

// 사전을 나타내는 트라이가 주어질 때, 단어 word를 타이픙하는 데 
// 몇 번이나 키를 눌러야 하는지 계산한다.
int countKeys(TrieNodePtr trie, const char* word) {
	auto node = trie->find(word);
	if (node == nullptr)
		return strlen(word);
	return trie->type(word, node->terminal);
}

int main() {
#ifdef _DEBUG
	freopen("solong.in", "r", stdin);
#endif

	int c, n, m, r;
	string w;
	cin >> c;
	while (c--) {
		cin >> n >> m;
		vector<pair<int, string>> dic;
		for (int i = 0; i < n; i++) {
			cin >> w >> r;
			dic.push_back({-r, w});
		}

		sort(dic.begin(), dic.end());
		auto Root = make_shared<TrieNode>();
		for (int i = 0; i < dic.size(); i++) {
			Root->insert(dic[i].second.c_str(), i);
		}
		Root->first = -1;
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
		string line;
		getline(cin, line);
		regex re(" ");
		sregex_token_iterator first(line.begin(), line.end(), re, -1), last;
		vector<string> lines(first, last);

		int keyType = 0;
		for (auto& l : lines) {
			int type = countKeys(Root, l.c_str());
			keyType += type + 1;
		}
		cout << (keyType - 1) << endl;
	}

	return 0;
}
