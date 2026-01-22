class StockSpanner {
public:
    // monotonic stack 
    stack<pair<int , int>> st ;  //{price , span}
    StockSpanner() {
        
    }
    
    int next(int price) {

        int span = 1 ; // currently span of price is 1 which is itself
        while(!st.empty() && price >= st.top().first){
            span += st.top().second ;
            st.pop();
        }
        st.push({price , span});

        return span ;
        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

//tc-->o(1) sc-->o(n)