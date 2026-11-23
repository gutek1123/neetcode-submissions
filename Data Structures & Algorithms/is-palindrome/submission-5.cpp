class Solution {
public:
    bool isPalindrome(string s) {
        std::size_t left = 0;
        std::size_t right = s.length() - 1;

        while (left < right){
            while(left < right && !std::isalnum(s[left])){
                left++;
            }
            while(left < right && !std::isalnum(s[right])){
                right--;
            }
            if(left >= right){
                break;
            }
            if( std::tolower(s[left]) != std::tolower(s[right])){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};
