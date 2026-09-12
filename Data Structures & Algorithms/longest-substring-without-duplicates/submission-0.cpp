class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::bitset<128> myCharacters(0);

        //abcabcabcabcd

        int longestNonDuplicateStringLen = 0;

        int left = 0;

        for(int i = 0; i < s.length(); i++){

            while(myCharacters.test(s[i])){
                myCharacters.reset(s[left]);
                left++;
            }

            myCharacters.set(s[i]);

            longestNonDuplicateStringLen = std::max(longestNonDuplicateStringLen, i - left + 1);
        }
        return longestNonDuplicateStringLen;
    }
};
