class MyQueue {
private:
    stack<int> st1, st2;

public:
    MyQueue() {
        st1 = st2 = stack<int>();
    }
    void push(int x) { st1.push(x); }

    int pop() {
        while (st1.size() > 1) {
            st2.push(st1.top());
            st1.pop();
        }
        int ret = st1.top();
        st1.pop();
        while (st2.size()) {
            st1.push(st2.top());
            st2.pop();
        }
        return ret;
    }

    int peek() {
         while (st1.size() > 1) {
            st2.push(st1.top());
            st1.pop();
        }
        int ret = st1.top();
        while (st2.size()) {
            st1.push(st2.top());
            st2.pop();
        }
        return ret;
    }

    bool empty() {
        return st1.size() == 0;
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
