class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int mostOccurences = 0;
        int element = 0;
        for(const auto& n: nums){
            if(mostOccurences == 0){
                element = n;
                mostOccurences = 1;
            }else if(element == n){
                mostOccurences++;
            }else {
                mostOccurences--;
            }
        }
        return element;
    }
};