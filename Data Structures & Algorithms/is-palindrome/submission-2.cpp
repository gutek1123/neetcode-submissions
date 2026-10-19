class Solution {
   public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.length() - 1;

        while (left < right) {
            while (!std::isalnum(s[left])) {
                if (left >= right) {
                    return true;
                }
                left++;
            }
            while (!std::isalnum(s[right])) {
                if (left >= right) {
                    return true;
                }
                right--;
            }
            if (std::tolower(s[left]) != std::tolower(s[right])) {
                return false;
            }
            right--;
            left++;
        }
        return true;
    }
};
