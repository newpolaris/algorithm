#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <queue>
#include <string.h>

using namespace std;

struct TrieNode;

const int MAX_CHAR = 26;
int char2num(char c) {
	return c - 'a';
}

struct TrieNode {
	// 현 위치에서 끝나는 문자열의 번호
	int terminal = -1;
	// 실패 연결: 이 노드에서 매칭이 실패했을 떄 이 곳으로 가서 계속한다.
	// 이 노드에 대응되는 문자열의 접미사이면서 트라이에 포함된 최대 문자열.
	TrieNode* fail = nullptr;
	// 출력 문자열 목록: 이 노드가 방문되었을 때 등장하는 바늘 문자열들의 번호
	vector<int> output;

	// 현재 상태의 번호
	int num = -1;

	TrieNode *child[MAX_CHAR], *next[MAX_CHAR];
	TrieNode() {
		memset(child, 0, sizeof(child));
	}
	~TrieNode() {
		for (int i = 0; i < MAX_CHAR; i++) {
			delete child[i];
			child[i] = nullptr;
		}
	}
	void insert(const char* str, int id) {
		if (*str == 0) {
			terminal = id;
		} else {
			auto ci = char2num(*str);
			if (!child[ci])
				child[ci] = new TrieNode;
			child[ci]->insert(str+1, id);
		}
	}
};

// 트라이가 주어질 때 각 노드에 대해 실패 연결과 출력 문자열 목록을 계산한다.
void computeFailFunc(TrieNode* root) {
	queue<TrieNode*> q;
	root->fail = root;
	q.push(root);
	while (!q.empty()) {
		auto here = q.front();
		q.pop();
		// here 의 모든 자손에 대해 실패 연결을 계산하고 큐에 넣는다
		for (int i = 0; i < MAX_CHAR; i++) {
			auto ch = here->child[i];
			if (!ch) continue;

			// 1 레벨의 실패는 루트
			if (here == root)
				ch->fail = root;
			else {
				// 아닌 경우 부모의 실패 연결을 따라가면서 실패 연결을 찾는다.
				auto t = here->fail;
				while (t != root && t->child[i] == nullptr)
					t = t->fail;
				if (t->child[i]) t = t->child[i];
				ch->fail = t;
			}
			// 출력 문자열 목록: 실패 연결을 따라간 노드에서 복사해온 뒤,
			// 이 위치에서 끝나는 바늘 문자열이 있으면 추가한다.
			ch->output = ch->fail->output;
			if (ch->terminal != -1)
				ch->output.push_back(ch->terminal);
			q.push(ch);
		}
	}
}

// 상태 간의 전의 테이블을 next[]에 채운다. computeFailFunc()를 통해
// 이미 실패 함수가 계산되어 있다고 가정한다
void computeTransition(TrieNode* here, int& nodeCounter) {
	// 0 에서시작하는 번호를 매긴다: cache[]의 인덱스
	here->num = nodeCounter++;

	// here 뒤에 글자 i 를 붙였을 때 어느 상태로 가는가?
	for (int i = 0; i < MAX_CHAR; i++) {
		// next[] 값을 계산해 저장한다.
		TrieNode* next = here;
		while (next != next->fail && next->child[i] == nullptr)
			next = next->fail;
		if (next->child[i]) next = next->child[i];
		here->next[i] = next;
		// 재귀적으로 모든 노드에 대해 전이 테이블을 게산한다.
		if (here->child[i])
			computeTransition(here->child[i], nodeCounter);
	}
}

// Aho-Corasick(아호-코라식)
// trie에 포함된 패턴들을 s에서 찾는다.
// s 내에서 패턴이 출현할 때마다 (마지막 글자, 패턴 번호)의 쌍을 저장한다.
vector<pair<int, int>> ahoCorasick(const string& s,
									TrieNode* root) {
	vector<pair<int, int>> ret;
	TrieNode* state = root;
	// 실제 반복문 내는 KMP와 별로 다른 것이 없다.
	for (int i = 0; i < s.size(); ++i) {
		int ch = char2num(s[i]);
		while (state != root && state->child[ch] == nullptr)
			state = state->fail;
		if (state->child[ch]) state = state->child[ch];
		for (int j = 0; j < state->output.size(); ++j)
			ret.push_back(make_pair(i, state->output[j]));
	}
	return ret;
}

const int MOD = 10007;
int cache[101][100*10+1];

int count(int n, TrieNode* node) {
	if (node->output.size()) 
		return 0;
	if (n == 0) return 1;
	
	int& ret = cache[n][node->num];
	if (ret >= 0) return ret;
	ret = 0;
	for (int i = 0; i < MAX_CHAR; i++) {
		ret += count(n-1, node->next[i]);
		ret %= MOD;
	}
	return ret;
}

int main() {
#ifdef _DEBUG
	freopen("nh.in", "r", stdin);
#endif

	int c, n, m;
	string s;
	cin >> c;
	while (c--) {
		cin >> n >> m;
		memset(cache, -1, sizeof(cache));

		TrieNode root;
		for (int i = 0; i < m; i++) {
			cin >> s;
			root.insert(s.c_str(), i);
		}
		int num = 0;
		computeFailFunc(&root);
		computeTransition(&root, num);
		cout << count(n, &root) << endl;
	}

	return 0;
}

