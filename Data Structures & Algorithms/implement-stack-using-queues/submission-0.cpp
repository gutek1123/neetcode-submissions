class MyStack {
   public:
    MyStack() {
        activeQueue = &q1;
        inactiveQueue = &q2;
    }

    void push(int x) {
        inactiveQueue->push(x);
        while (!activeQueue->empty()) {
            inactiveQueue->push(activeQueue->front());
            activeQueue->pop();
        }
        std::swap(activeQueue, inactiveQueue);
    }

    int pop() {
        int toRet = activeQueue->front();
        activeQueue->pop();
        return toRet;
    }

    int top() {
        return activeQueue->front();
    }

    bool empty() {
        return activeQueue->empty();
    }

   private:
    std::queue<int> q1, q2;
    std::queue<int>*activeQueue, *inactiveQueue;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */