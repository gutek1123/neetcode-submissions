class Solution {
public:
    int getSum(int a, int b) {
        int carry = 0;
        int result = 0;
        for(int i = 0; i < 32;i++){
            
            if(((a >> i & 1) & (b >> i & 1)) == 1){
                if(carry == 1){
                    result |= 1 << i;
                }
                carry = 1;
                continue;
            }

            if((((a >> i) & 1) ^ ((b >> i) & 1)) == 1){
                if(carry){
                    continue;
                }
                carry = 0;
                result |= 1 << i;
            }else {
                if(carry){
                    carry = 0;
                    result |= 1 << i;
                }
            }


        }
        return result;
    }
};
