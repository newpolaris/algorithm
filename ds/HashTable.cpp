#include <iostream>
#include <vector>
#include <list>
#include <cassert>
#include <experimental/optional>

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

namespace hash {
	using std::list;
	using std::vector;
	using std::experimental::nullopt;
	using std::experimental::optional;
	const int LoadFactor = 5;

	class HashTable {
	private:
		using Node = std::pair<Key, int>;
		struct HashTableNode {
			list<Node> list_;
		};
		int count_ = 0;
		vector<HashTableNode> table_;

		// if already exist return false
		// else true
		bool insert(std::pair<Key, int>&& p) {
			if (find(p.first) != nullopt) 
				return false;
			auto k = Hash(p.first);
			auto& chain = table_[k].list_;
			chain.push_front(p);
			return false;
		}

		int Hash(const Key& key) {
			return 0;
		}

		optional<int> find(const Key& key) {
			auto k = Hash(key);
			auto& chain = table_[k].list_;
			for (auto& c : chain) {
				if (c.first == key) 
					return nullopt; 
			}
			return k;
		}

	public:
		HashTable(int size) {
			table_.resize(size/LoadFactor);
		}

		bool insert(Key&& key, int data) {
			return insert(std::make_pair(key, data));
		}

		bool insert(const int& key, int data) {
			return insert(std::make_pair(key, data));
		}

	};
}

int main() {

	hash::HashTable h(10);
	std::vector<int> v(10);
	h.insert(Key(), 10);

	return 0;
}
