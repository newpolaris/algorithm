#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <memory>

#include "print_binary_tree.hpp"

using namespace std;

/*
 * note : rand is fast enough
 * speed up 
 * 	comment - just 2x fast http://stackoverflow.com/a/3747462
 *
 inline int fastrand() { 
	 g_seed = (214013*g_seed+2531011); 
	 return (g_seed>>16)&0x7FFF; 
 } 
 */
typedef int KeyType;

// 트립의 한 노드를 저장한다.
struct Node {
	// 이 노드의 우선 순위, 이 노드를 루트로 하는 서브트리의 크기
	int priority, size;
	// 노드에 저장된 원소
	KeyType key;
	Node *left, *right;

	// 생성자에서 난수 우선 순위를 생성하고, size 와 left/right를 초기화 한다.
	Node(KeyType key) : priority(rand()),
		left(nullptr), right(nullptr), 
		key(move(key)), size(1)  {}
	~Node() {
		delete left;
		left = nullptr;
		delete right;
		right = nullptr;
	}
	void setLeft(Node* l) {
		left = l; 
		calcSize(); 
	}
	void setRight(Node* r) {
		right = r;
		calcSize(); 
	}
	// element 갱신
	void calcSize() {
		size = 1;
		if (left) size += left->size;
		if (right) size += right->size;
	}
};

typedef pair<Node*, Node*> NodePair;

// root 를 루트로 하는 트립을 key미만의 값과 이상의 값을 갖는
// 두개의 트립으로 분리한다
NodePair split(Node* root, KeyType key) {
	if (!root) return { nullptr, nullptr };

	// 이상(같은 키 포함) 일 경우 왼쪽을 쪼갠다
	if (key <= root->key) {
		auto pair = split(root->left, key);
		root->setLeft(pair.second);
		return { pair.first, root };
	} else {
		auto pair = split(root->right, key);
		root->setRight(pair.first);
		return { root, pair.second };
	}
}

Node* insert(Node* root, Node* node) {
	if (!root) return node;
	// node가 루트를 대체해야 한다. 해당 서브 트리를 반으로 잘라
	// 각각 자손으로 한다
	if (root->priority < node->priority) {
		auto pair = split(root, node->key);
		node->setLeft(pair.first);
		node->setRight(pair.second);
		return node;
	} else if (node->key < root->key) {
		root->setLeft(insert(root->left, node));
	// 같은 키 일 경우 오른쪽
	} else {
		root->setRight(insert(root->right, node));
	}
	return root;
}

// a 와 b가 두개의 트립이고, key 값이 max(a) < min(b) 일 떄 이 둘을 합친다.
Node* merge(Node* a, Node* b) {
	if (!a) return b;
	if (!b) return a;
	// left rotate
	if (a->priority < b->priority) {
		b->setLeft(merge(a, b->left));
		return b;
	// right rotate
	} else {
		a->setRight(merge(a->right, b));
		return a;
	}
}

// root를 루트로 하는 트립에서 key를 지우고 결과 트립의 루트를 반환한다
Node* erase(Node* root, KeyType key) {
	if (!root) return root;
	if (root->key == key) {
		auto node = merge(root->left, root->right);
		root->left = nullptr;
		root->right = nullptr;
		delete root;
		return node;
	} else {
		if (key < root->key)
			root->setLeft(erase(root->left, key));
		else
			root->setRight(erase(root->right, key));
	}
	return root;
}

Node* kth(Node* root, int k) {
	int leftSize = 0;
	if (root->left != nullptr) leftSize = root->left->size;
	if (k <= leftSize) return kth(root->left, k);
	if (k == leftSize + 1) return root;
	return kth(root->right, k - leftSize - 1);
}

// key 미만을 가지는 node 의 수를 반환한다
int countLessThan(Node* root, KeyType key) {
	if (root == NULL) return 0;
	if (root->key >= key)
		return countLessThan(root->left, key);
	int ls = (root->left ? root->left->size : 0);
	return ls + 1 + countLessThan(root->right, key);
}

// print_binary_tree 를 위한 출력 stream
std::ostream& operator<<(std::ostream& strm, const Node& node) {
	return strm << node.key << "," << node.size;
}

int main()
{
	Node* root = nullptr;
	root = insert(root, new Node(10));
	root = insert(root, new Node(15));
	root = insert(root, new Node(3));
	print_ascii_tree(root);
	root = erase(root, 3);
	print_ascii_tree(root);
	root = erase(root, 15);
	print_ascii_tree(root);
	root = erase(root, 10);

	root = insert(root, new Node(10));
	root = insert(root, new Node(1));
	root = insert(root, new Node(10));
	root = insert(root, new Node(1));
	root = insert(root, new Node(10));
	root = insert(root, new Node(1));
	root = insert(root, new Node(10));
	root = insert(root, new Node(10));
	root = insert(root, new Node(10));
	root = insert(root, new Node(10));
	root = insert(root, new Node(1));
	root = insert(root, new Node(1));
	root = insert(root, new Node(1));
	root = insert(root, new Node(1));
	print_ascii_tree(root);

	delete root;
	root = nullptr;

	return 0;
}

