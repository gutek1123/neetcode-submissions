class Solution {
public:
    int mySqrt(int x) {
        int left = 0;
        int right = x/2 + 1;
        int result = 0;

        while(left <= right){
            int middle = left + (right - left) / 2;

            long long power = (long long)middle * middle;

            if(power == x){
                return middle;
            }else if(power > x){
                right = middle - 1;
            }else {
                result = middle;
                left = middle + 1;
            }
        }
        return result;
    }
};