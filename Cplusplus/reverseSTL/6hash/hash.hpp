#pragma once

#include <iostream>
#include <vector>

namespace cjj {
    using std::cout;
    using std::endl;
    using std::pair;
    using std::make_pair;
    using std::vector;

    namespace OpenHash {

    }


    namespace ZipHash {
        template<class K, class V>
        struct HashNode {
            explicit HashNode(const pair<K, V> &kv)
                    : _kv(kv), _next(nullptr) {}

            HashNode<K, V> *_next;
            pair<K, V> _kv;
        };

        template<class K>
        struct HashKey {
            size_t operator()(const K &k) {
                return k;
            }
        };

        template<>
        struct HashKey<std::string> {
            // BKDR哈希
            size_t operator()(const std::string &s) {
                size_t hash = 0;
                for (auto &ch: s) {
                    hash = hash * 31 + ch;
                }
                return hash;
            }
        };

        template<class K, class V, class Hash = HashKey<K>>
        class HashTable {
            using Node = HashNode<K, V>;
        public:
            HashTable() = default;

            ~HashTable() noexcept {
                for (auto &cur: _hash) {
                    while (cur) {
                        Node *next = cur->_next;
                        delete cur;
                        cur = next;
                    }
                }
            }

            size_t size() const noexcept {
                return _size;
            }

            Node *find(const K &key) const noexcept {
                HashKey<K> hashKey;
                size_t index = hashKey(key) % _hash.size();
                Node *cur = _hash[index];
                while (cur) {
                    if (cur->_kv.first == key) {
                        return cur;
                    }
                    cur = cur->_next;
                }
                return nullptr;
            }

            bool insert(const pair<K, V> &kv) noexcept {
                HashKey<K> hashKey;
                _checkSize();
                if (find(kv.first)) {
                    return false;
                }
                size_t index = hashKey(kv.first) % _hash.size();
                Node *newNode = new Node(kv);
                newNode->_next = _hash[index];
                _hash[index] = newNode;
                _size++;
                return true;
            }

            bool erase(const K &key) noexcept {
                HashKey<K> hashKey;

                size_t index = hashKey(key) % _hash.size();
                Node *prev = nullptr;
                Node *cur = _hash[index];
                while (cur) {
                    if (cur->_kv.first == key) {
                        if (prev == nullptr) {
                            _hash[index] = cur->_next;
                        } else {
                            prev->_next = cur->_next;
                        }
                        delete cur;
                        _size--;
                        return true;
                    } else {
                        prev = cur;
                        cur = cur->_next;
                    }
                }
                return false;
            }

            size_t maxBuket() {
                size_t max = 0;
                for (int i = 0; i < _hash.size(); ++i) {
                    auto cur = _hash[i];
                    size_t len = 0;
                    while (cur) {
                        len ++ ;
                        cur = cur->_next;
                    }
                    max = std::max(len, max);
                    if (len != 0) {
                        printf("[%d]->%d\n", i, len);
                    }
                }
                return max;
            };

        private:
            void _checkSize() noexcept {
                // 扩容
                if (_hash.empty() || _hash.size() == _size) {
                    HashKey<K> hashKey;

                    size_t newSize = _hash.empty() ? 5 : _hash.size() * 2;
                    vector<Node *> newTable;
                    newTable.resize(newSize, nullptr);

                    for (auto &cur: _hash) {
                        while (cur) {
                            Node *next = cur->_next;
                            size_t newIndex = hashKey(cur->_kv.first) % newSize;
                            cur->_next = newTable[newIndex];
                            newTable[newIndex] = cur;
                            cur = next;
                        }
                        cur = nullptr;
                    }
                    newTable.swap(_hash);
                }
            }

            vector<Node *> _hash;
            size_t _size = 0;
        };
    }

    void testZipHash() {
        using namespace ZipHash;

        HashTable<int, int> hash;

        hash.insert(make_pair(1, 10));
        hash.insert(make_pair(11, 10));
        hash.insert(make_pair(111, 10));
        hash.insert(make_pair(2, 10));
        hash.insert(make_pair(22, 10));

        hash.insert(make_pair(222, 10));

        hash.erase(222);
        hash.erase(22);
        hash.erase(2);

        hash.erase(11);
    }

    void testZipHash2() {
        ZipHash::HashTable<int, int> hash;

        srand(time(nullptr));

        const int N = 1000;
        for (int i = 0; i < N; ++i) {
            int tmp = rand() + i;
            hash.insert(make_pair(tmp, tmp));
        }

        cout << hash.maxBuket() << endl;
        cout << hash.size() << endl;
    }
}