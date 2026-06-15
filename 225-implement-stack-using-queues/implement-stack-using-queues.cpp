class MyStack {
    // sc --> O(k) k ele stored
    queue<int> q ;
public:
    MyStack() {

    }
    
    void push(int x) {
        // O(s)
        int s = q.size() ;
        q.push(x) ;

        // to maintain stack top order 
        for(int i = 0 ; i<s ; i++){
            q.push(q.front()) ;
            q.pop() ;
        }
        
    }
    
    int pop() {
        //O(1)
        int ele = q.front() ;
        q.pop();
        return ele ;

        
    }
    
    int top() {
        //O(1)
        return q.front() ;
        
    }
    
    bool empty() {
        //O(1)
        return q.empty() ;
        
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */