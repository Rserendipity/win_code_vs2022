class ExamRoom {
public:
    set<int> st;
    int n;
    ExamRoom(int N) {
        n = N;
    }
    int seat() {
        if (st.empty()) {
            st.insert(0); 
            return 0;
        }
        int pre = *st.begin(), idx = 0, mx = pre;
        for (auto u : st) {
            if ((u - pre) / 2 > mx) {
                idx = (u + pre) / 2;
                mx = (u - pre) / 2;
            }
            pre = u; 
        }
        if (n - 1 - pre > mx) {
            idx = n - 1;
        }
        st.insert(idx);
        return idx;
    }
    
    void leave(int p) {
        st.erase(p);
    }
};
