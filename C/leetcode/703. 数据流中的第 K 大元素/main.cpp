class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        _k = k;
        for (auto& n : nums) {
            add(n);
        }
    }
    
    int add(int val) {
        pq.push(val);
        if (pq.size() > _k) {
            pq.pop();
        }
        return pq.top();
    }
private:
    priority_queue<int, vector<int>, greater<int>> pq;
    int _k;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */