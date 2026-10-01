class Solution {
   public:
    string longestPalindrome(string s) {
        int longestSubstr = 0;
        int longestStart = 0;

        for (int i = 0; i < s.length(); i++) {
            for (int j = i, k = i; j < s.length() && k >= 0; j++, k--) {
                if (s[j] != s[k]) {
                    break;
                }

                int len = j - k + 1;
                if (len > longestSubstr) {
                    longestSubstr = len;
                    longestStart = k;
                }
            }

            for (int j = i + 1, k = i; j < s.length() && k >= 0; j++, k--) {
                if (s[j] != s[k]) {
                    break;
                }

                int len = j - k + 1;
                if (len > longestSubstr) {
                    longestSubstr = len;
                    longestStart = k;
                }
            }
        }
        return s.substr(longestStart, longestSubstr);
    }
};
