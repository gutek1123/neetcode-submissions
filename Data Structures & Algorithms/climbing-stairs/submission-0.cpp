class Solution {
public:
    int climbStairs(int n) {
        std::queue<int> myQueue;
        myQueue.push(0);
        myQueue.push(1);
        for(int i = 0; i < n; i++){
            myQueue.push(myQueue.back() + myQueue.front());
            myQueue.pop();
        }
        return myQueue.back();
    }
};
