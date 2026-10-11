class MedianFinder {
   public:
    MedianFinder() {}

    void addNum(int num) {
        smallHeap.push(num);
        if (!largeHeap.empty() && smallHeap.top() > largeHeap.top()) {
            largeHeap.push(smallHeap.top());
            smallHeap.pop();
        }
        if (smallHeap.size() > largeHeap.size() + 1) {
            largeHeap.push(smallHeap.top());
            smallHeap.pop();
        }
        if (largeHeap.size() > smallHeap.size() + 1) {
            smallHeap.push(largeHeap.top());
            largeHeap.pop();
        }
    }

    double findMedian() {
        if(largeHeap.size() == smallHeap.size()){
            return (largeHeap.top() + smallHeap.top()) / 2.0f;
        }else if(largeHeap.size() > smallHeap.size()){
            return static_cast<double>(largeHeap.top());
        }else {
            return static_cast<double>(smallHeap.top());
        }
    }

   private:
    std::priority_queue<int, std::vector<int>, std::less<int>> smallHeap;
    std::priority_queue<int, std::vector<int>, std::greater<int>> largeHeap;
};
