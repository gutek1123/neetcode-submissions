class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majority = 0;
        int occ = 0;
        for(const auto& n: nums){
            if(occ == 0){
                majority = n;
                occ++;
            }
            if(majority == n){
                occ++;
            }else{
                occ--;
            }

        }
        return majority;
    }
};