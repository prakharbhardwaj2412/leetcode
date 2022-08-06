class MyStack {
public:
    queue<int> q1, q2;
    
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        int x=q1.back();
        int temp1, temp2;
        temp1=temp2=q1.front();
        q1.pop();
        while(!q1.empty())
        {
            temp1=temp2;
            temp2=q1.front();
            q2.push(temp1);
            q1.pop();
        }
        while(!q2.empty())
        {
            int temp=q2.front();
            q1.push(temp);
            q2.pop();
        }
        return x;
    }
    
    int top() {
        return q1.back();
    }
    
    bool empty() {
        return q1.empty();
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