class Solution {
   public:
    bool isPalindrome(string s) {
        int left = 0, right = s.length() - 1;

        auto isValidCharacter = [](char c) -> bool {
            if ((c <= 'z' && c >= 'a') || (c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z')) {
                return true;
            }
            return false;
        };

        while (left < right) {
            while (!isValidCharacter(s[left]) && left < right) {
                left++;
            }
            while (!isValidCharacter(s[right]) && left < right) {
                right--;
            }
            if (std::tolower(s[left]) != std::tolower(s[right])) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};
