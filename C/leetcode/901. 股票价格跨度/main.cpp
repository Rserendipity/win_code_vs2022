class StockSpanner
{
public:
    StockSpanner()
    {
        st.emplace(-1, INT_MAX);
        index = -1;
    }

    int next(int price)
    {
        index++;
        while (price >= st.top().second)
        {
            st.pop();
        }
        int ret = index - st.top().first;
        st.emplace(index, price);
        return ret;
    }

private:
    stack<pair<int, int>> st;
    int index;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */