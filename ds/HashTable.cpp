#include <iostream>
#include <vector>
#include <list>
#include <cassert>
#include <functional>

namespace test {
	using std::cout;
	using std::endl;
	struct Test {
		int k_;
		Test(int k) : k_(k) {
			cout << k_ << " C" << endl;
		}
		virtual ~Test() {
			cout << k_ << " D" << endl;
		}
		Test(const Test& h) {
			k_ = h.k_;
			cout << k_ << " COPY" << endl;
		}
		Test(Test&& h) : k_(0) {
			*this = std::move(h);
			cout << " MOVE C" << endl;
		}
		Test& operator=(Test&&) = default;
	};
	bool operator==(const Test& a, const Test& b) { return a.k_ == b.k_; }
}

namespace std {
	template<> struct hash<test::Test> {
        typedef test::Test argument_type;
        typedef std::size_t result_type;
        result_type operator()(argument_type const& s) const {
            return hash<int>{}(s.k_);
        }
	};
}

namespace hashtable {
	using std::list;
	using std::vector;

	template <typename Key>
	int Hash(const Key& key) {
		int h = std::hash<Key>{}(key);
		// from java hash mix. (c++ ref example h ^ (h << 1))
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
		HashTable(int size) {
			table_.resize(1 + size/LoadFactor);
		}

		Val* find(const Key& key) {
			int k = index(key);
			auto& chain = table_[k].list_;
			for (auto& c : chain) {
				if (c.first == key) {
					return &c.second;
				}
			}
			return nullptr; 
		}

		// if already exist return false
		// else true
		bool insert(Node&& p) {
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

		// public insert function can handle rvalue-reference
		bool insert(Key&& key, int data) {
			return insert(std::make_pair(std::move(key), data));
		}

		// public insert function can handle const lvalue
		bool insert(const Key& key, int data) {
			return insert(std::make_pair(key, data));
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

		Val& operator[](const Key& key) {
			int k = index(key);
			auto& chain = table_[k].list_;
			for (auto& c : chain) {
				if (c.first == key) {
					return c.second;
				}
			}
			return insert(std::make_pair(key, Val())).first->second;
		}

		void clear() {
			table_.clear();
			count_ = 0;
		}
	};
}

int main() {
	using Key=test::Test;;
	using Val=int;

	hashtable::HashTable<Key, Val> h(1);
	h.insert(Key(1), 10);
	h.insert(Key(2), 9);
	assert(h.find(Key(2)) != nullptr);
	h.insert(Key(3), 8);
	h.insert(Key(4), 7);
	h.insert(Key(5), 6);
	h.insert(Key(6), 5);
	assert(h.find(Key(2)) != nullptr);
	assert(h.find(Key(6)) != nullptr);
	*h.find(Key(6)) = 1;
	assert(*h.find(Key(6)) == 1);

	return 0;
}
