class KthLargest {
   public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (const auto& n : nums) {
            minHeap.push(n);
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
    }

    int add(int val) {
        minHeap.push(val);
        if (minHeap.size() > k) {
            minHeap.pop();
        }
        return minHeap.top();
    }

   private:
    int k;
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
};
