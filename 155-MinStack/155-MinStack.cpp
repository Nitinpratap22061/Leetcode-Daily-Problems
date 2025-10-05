// Last updated: 10/5/2025, 9:00:48 AM
class MinStack {
public:
  int mini =INT_MAX;
   stack<pair<int,int>>st;
    MinStack() {
       
    }
    
    void push(int val) {
        int a = val ; 
        mini = min(mini,val);
        st.push({a,mini});
    }
    
    void pop() {
        if(!st.empty())
        {
        st.pop();
        mini = st.empty() ? INT_MAX : st.top().second;
        }
        
    }
    
    int top() {
        
        if(!st.empty())
        {
         return st.top().first;
        }
        return -1;
        
    }
    
    int getMin() {
        if(!st.empty())
        {
        return st.top().second;
        }
        return -1;

        
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */