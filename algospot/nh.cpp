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

	int num = -1;

	TrieNode* child[MAX_CHAR];
	TrieNode() {
		for (int i = 0; i < MAX_CHAR; i++)
			child[i] = nullptr;
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
	int node_num = 0;
	queue<TrieNode*> q;
	root->fail = root;
	q.push(root);
	while (!q.empty()) {
		auto here = q.front();

		// node에 numering 부여 dp 상에서 구분하도록
		here->num = node_num++;

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
		auto ch = node;
		while (ch != ch->fail && ch->child[i] == nullptr)
			ch = ch->fail;
		if (ch->child[i]) ch = ch->child[i];
		ret += count(n-1, ch);
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
		computeFailFunc(&root);
		cout << count(n, &root) << endl;
	}

	return 0;
}

