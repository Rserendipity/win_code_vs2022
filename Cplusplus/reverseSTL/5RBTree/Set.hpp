#pragma once
#include "RBTree.hpp"

namespace cjj_stl {
    template<class K>
    class set {
    private:
        struct SetKeyOfT {
            const K& operator()(const K& key) {
                return key;
            }
        };
    public:
        bool insert(const K& key) {
            return _t.insert(key);
        }


    private:
        RBTree<K, K, SetKeyOfT> _t;
    };

    void testMap1() {
        set<int> hash;
        hash.insert(10);
    }
}