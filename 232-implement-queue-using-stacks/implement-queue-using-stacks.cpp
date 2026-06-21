class MyQueue {
public:
    stack<int> st;
    stack<int> temp;
    MyQueue() {
        
    }
    
    void push(int x) {
        while(!st.empty()){
            int tp = st.top();
            st.pop();
            temp.push(tp);
        }
        st.push(x);
        while(!temp.empty()){
            int tp = temp.top();
            temp.pop();
            st.push(tp);
        }
    }
    
    int pop() {
        if(st.empty()) return -1;
        int tp = st.top();
        st.pop();
        return tp;
    }
    
    int peek() {
        if(st.empty()) return -1;
        return st.top();
    }
    
    bool empty() {
        if(st.empty()) return true;
        else return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */