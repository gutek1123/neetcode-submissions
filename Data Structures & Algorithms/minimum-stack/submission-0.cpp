class MinStack {
   public:
    MinStack() {}

    void push(int val) {
        if (vec.empty()) {
            vec.push_back({val, val});
        } else {
            int min = std::min(vec.back().second, val);
            vec.push_back({val, min});
        }
    }

    void pop() {
        vec.pop_back();
    }

    int top() {
        return vec.back().first;
    }

    int getMin() {
        return vec.back().second;
    }

   private:
    std::vector<std::pair<int, int>> vec;
};
