class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_set<int> mySet(nums.begin(), nums.end());

        int longestChain = 0;

        for(const auto& n : mySet){

            if(mySet.find(n - 1) != mySet.end()){
                continue;
            }

            int currentChain = 1;

            while(mySet.find(n + currentChain) != mySet.end()){
                currentChain++;
            }

            longestChain = std::max(longestChain, currentChain);
        }

        return longestChain;
    }
};
