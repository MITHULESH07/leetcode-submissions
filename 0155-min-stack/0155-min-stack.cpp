class MinStack {
public:
    stack<int>st,minSt;
    MinStack() {
        minSt.push(INT_MAX);
    }
    
    void push(int value) {
        st.push(value);
        minSt.push(min(minSt.top() , value));
    }
    
    void pop() {
        st.pop();
        minSt.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSt.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */