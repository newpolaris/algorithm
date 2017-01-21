#include <iostream>
#include <vector>
#include <list>
#include <cassert>
#include <boost/optional.hpp>

namespace test {
	using std::cout;
	using std::endl;
	struct Test {
		Test() {
			cout << "H" << endl;
		}
		Test(const Test& h) {
			cout << "H2" << endl;
		}
		Test(Test&& h) {
			cout << "H3" << endl;
		}
	};
}

// Temp
using Key=int;
using Val=int;

namespace hash {
	using std::list;
	using std::vector;
	using boost::optional;
	using boost::none;
	const int LoadFactor = 5;

	class HashTable {
	private:
		using Node = std::pair<Key, Val>;
		struct HashTableNode {
			list<Node> list_;
		};
		int count_ = 0;
		vector<HashTableNode> table_;

		// if already exist return false
		// else true
		bool insert(std::pair<Key, Val>&& p) {
			if (find(p.first) != none) 
				return false;

			auto k = Hash(p.first);
			auto& chain = table_[k].list_;
			chain.push_front(p);
			return false;
		}

		int Hash(const Key& key) {
			return 0;
		}

	public:
		HashTable(int size) {
			table_.resize(size/LoadFactor);
		}

		// optional test
		optional<Val&> find(const Key& key) {
			auto k = Hash(key);
			auto& chain = table_[k].list_;
			for (auto& c : chain) {
				if (c.first == key) {
					// https://goo.gl/FO9J6i
					// optional reference binding : portability issue
					return c.second;
				}
			}
			// null value
			return none; 
		}


		// public insert function can handle rvalue-reference
		bool insert(Key&& key, int data) {
			return insert(std::make_pair(key, data));
		}

		// public insert function can handle const lvalue
		bool insert(const int& key, int data) {
			return insert(std::make_pair(key, data));
		}

		bool remove(const Key& key) {
			auto k = Hash(key);
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
	};
}

int main() {

	hash::HashTable h(10);
	std::vector<int> v(10);
	h.insert(Key(), 5);
	auto t = h.find(Key());
	if (t.is_initialized()) 
		t.get() = 10;

	return 0;
}
