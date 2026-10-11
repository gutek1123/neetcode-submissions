class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        std::priority_queue<int> minHeap;
        for(const auto& n : nums){
            minHeap.push(n);
        }
        for(int i = 1; i < k; i++){
            minHeap.pop();
        }
        return minHeap.top();
    }
};
