class LRUCache
{
    struct Node
    {
        int key;
        int val;
        Node *prev;
        Node *next;
        Node(int k, int v)
            : key(k), val(v), prev(nullptr), next(nullptr) {}
    };

    class List
    {
    public:
        List()
        {
            _head = new Node(-1, -1);
            _head->prev = _head;
            _head->next = _head;
        }
        ~List()
        {
            auto cur = _head->next;
            while (cur != _head)
            {
                auto save = cur->next;
                delete cur;
                cur = save;
            }
            delete _head;
        }

        void push_front(Node *node)
        {
            node->next = _head->next;
            _head->next->prev = node;
            _head->next = node;
            node->prev = _head;
        }

        Node *pop_back()
        {
            auto node = _head->prev;
            node->prev->next = _head;
            _head->prev = node->prev;
            return node;
        }

        void erase(Node *node)
        {
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }

    private:
        Node *_head;
    };

public:
    LRUCache(int capacity) { this->capacity = capacity; }

    int get(int key)
    {
        if (hash.count(key) != 0)
        {
            auto node = hash[key]; // 拿到节点，然后更新到最前端
            lt.erase(node);
            lt.push_front(node);
            return node->val;
        }
        else
        {
            return -1;
        }
    }

    void put(int key, int value)
    {
        if (hash.count(key) != 0)
        {                          // 存在，更新值
            auto node = hash[key]; // 拿到节点，然后更新到最前端
            lt.erase(node);
            lt.push_front(node);
            node->val = value;
        }
        else
        {
            auto node = new Node(key, value);
            hash[key] = node;
            lt.push_front(node);
        }

        if (hash.size() > capacity)
        {
            auto node = lt.pop_back();
            hash.erase(node->key);
            delete node;
        }
    }

private:
    int capacity;
    List lt;
    unordered_map<int, Node *> hash; // key:index
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */