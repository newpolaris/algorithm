// iddaga's solustion 347ms
#include <stdio.h>
#include <memory.h>
#include <map>

#define ML 4096
#define ll long long
#include <list>
#include <vector>
#include <functional>
#define MOD 10000000000013LL

namespace hashtable {
	using std::list;
	using std::vector;

	template <typename Key>
	int Hash(const Key& key) {
		int h = std::hash<Key>{}(key);
		return (h ^ (h >> 16));
	}

	template <typename Key, typename Val>
	class HashTable {
	private:
		using Node = std::pair<Key, Val>;
		const int LoadFactor = 5;
		struct HashTableNode {
			list<Node> list_;
		};
		int count_ = 0;
		vector<HashTableNode> table_;

		int index(const Key& key, int size) {
			return Hash(key) % size;
		}
		int index(const Key& key) {
			return index(key, table_.size());
		}

		void rehash() {
			decltype(table_) table(table_.size()*2);
			int count = 0;

			for (auto& c : table_) {
				for (auto& l : c.list_) {
					auto k = index(l.first, table.size());
					auto& chain = table[k].list_;
					chain.push_front(move(l));
					count++;
				}
			}
			// std::move is used so, it isn't guarantee table_ is not modified on exception occurs.
			std::swap(table_, table);
			std::swap(count_, count);
		}

	public:
		HashTable() {
		}

		Val* find(Key&& key) {
			return find(key);
		}

		Val* find(const Key& key) {
			if (table_.empty()) 
				return nullptr;

			int k = index(key);
			auto& chain = table_[k].list_;
			for (auto& c : chain) {
				if (c.first == key) {
					return &c.second;
				}
			}
			return nullptr; 
		}


		// public insert function can handle rvalue-reference
		bool insert(Key&& key, int data) {
			return insert(std::make_pair(std::move(key), data));
		}

		// public insert function can handle const lvalue
		bool insert(const int& key, int data) {
			return insert(std::make_pair(key, data));
		}

		// if already exist return false
		// else true
		bool insert(Node&& p) {
			if (table_.empty()) {
				table_.resize(1);
			}
			if (find(p.first) != nullptr) 
				return false;

			auto k = index(p.first);
			auto& chain = table_[k].list_;
			chain.push_front(std::move(p));
			count_++;

			if (count_ / table_.size() > LoadFactor)
				rehash();

			return true;
		}

		bool remove(const Key& key) {
			auto k = index(key);
			auto& chain = table_[k].list_;
			for (auto iter = chain.begin();
				 iter != chain.end();
				 ++iter) {
				if (iter->first == key) {
					iter = chain.erase(iter);
					return true;
				}
			}
			return false;
		}

		void clear() {
			table_.clear();
			count_ = 0;
		}
	};
}

using namespace std;

int n, k;
char d[ML];

hashtable::HashTable<ll,int> c;
// map<ll,int> c;

bool help(int m) {
    int i, j;
	ll t, v;

	t = 1; 
	for (i = 0; i < m; i++) 
		t = t*26%MOD;

	c.clear();
	v = 0;
	for (i = 0; i < n; i++) {
		v = (v*26 + d[i]-'a')%MOD;
		if (i-m >= 0) {
			v -= t*(d[i-m]-'a')%MOD;
			if (v < 0) v += MOD;
		}
		if (i+1 >= m) {
			auto p = c.find(v);
			if (p == nullptr) c.insert({v, 0});
			if (++(*c.find(v)) == k) return 1;
		}
	}
	return 0;
}

int main()
{
#ifdef _DEBUG
	freopen("habit.in", "r", stdin);
#endif
	int t, T, s, e, m;

	scanf("%d",&T);
	for (t = 0; t < T; t++) {
		scanf("%d%s", &k, d);
		for (n = 0; d[n]; n++);
		for (s = 1, e = n; s <= e;) {
			m = (s+e)/2;
			if (help(m)) s = m+1;
			else e = m-1;
		}
		printf("%d\n",s-1);
	}
	return 0;
}
