#pragma once
#include "RBTree.hpp"

namespace cjj_stl {
    template<class K, class V>
    class map {
    private:
        struct MapKeyOfT {
            const K& operator()(const std::pair<const K, V> kv) {
                return kv.first;
            }
        };
    public:
        using  iterator = typename RBTree<K, std::pair<const K, V>, MapKeyOfT>::iterator;
        iterator begin() {
            return _t.begin();
        }
        iterator end() {
            return _t.end();
        }

        bool insert(const std::pair<const K, V>& kv) {
            return _t.insert(kv);
        }

    private:
        RBTree<K, std::pair<const K, V>, MapKeyOfT> _t;
    };

    void testMap1() {
        map<int, int> hash;
        hash.insert(std::make_pair(10, 20));
        hash.insert(std::make_pair(20, 20));
        hash.insert(std::make_pair(30, 20));
        hash.insert(std::make_pair(40, 20));

        cout << "this" << endl;
        for (auto kv : hash) {
            cout << kv.first << endl;
        }
    }
}