#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <iterator>

#define REP(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

using namespace std;

struct List;
struct List
{
	int data = 0;
	List* next = nullptr;
};

// scala, hasekll : reverse(tail) ++ head

// reculsive version: new head retrun
List* reverse2(List* node) {
	if (node == nullptr) return node;
	if (node->next == nullptr) return node;
	// 초기화 시켜둬서 termial 될때 문제 대비
	List* next = nullptr;
	swap(node->next, next);
	/*
	 * auto next = node->next;
	 * node->next = nullptr;
	 */
	auto newhead = reverse2(next);
	next->next = node;
	return newhead;
}

// iterative version : 깔끔하고 괜찮네
List* reverse(List* node) {
	if (node == nullptr) 
		return node;
	List* pre = nullptr;
	auto cur = node;
	while (cur != nullptr) {
		auto next = cur->next;
		cur->next = pre;
		pre = cur;
		cur = next;
	}
	return pre;
}

ostream& operator<<(ostream& o, const List& l) {
	o << l.data;
	return o;
}

void printList(List* node) {
	auto ptr = node;
	while (ptr != nullptr) {
		cout << *ptr << " ";
		ptr = ptr->next;
	}
	cout << endl;
}

int main() {
	vector<List> hello(10);
	for (int i = 0; i < hello.size(); i++)
		hello[i].data = i + 1;
	for (int i = hello.size() - 2; i >= 0; i--)
		hello[i].next = &hello[i+1];

	printList(&hello[0]);
	auto h = &hello[0];
	h = reverse(h);
	printList(h);
	h = reverse2(h);
	printList(h);
	cout << endl;

	return 0;
}
