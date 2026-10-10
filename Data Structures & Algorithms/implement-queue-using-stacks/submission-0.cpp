class MyQueue {
   public:
    MyQueue() {}

    void push(int x) { myStack.push(x); }

    int pop() {
        while (!myStack.empty()) {
            helperStack.push(myStack.top());
            myStack.pop();
        }

        int val = helperStack.top();

        helperStack.pop();

        while (!helperStack.empty()) {
            myStack.push(helperStack.top());
            helperStack.pop();
        }

        return val;
    }

    int peek() {
        while (!myStack.empty()) {
            helperStack.push(myStack.top());
            myStack.pop();
        }

        int val = helperStack.top();

        while (!helperStack.empty()) {
            myStack.push(helperStack.top());
            helperStack.pop();
        }

        return val;
    }

    bool empty() { return myStack.empty(); }

   private:
    std::stack<int> myStack;
    std::stack<int> helperStack;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */