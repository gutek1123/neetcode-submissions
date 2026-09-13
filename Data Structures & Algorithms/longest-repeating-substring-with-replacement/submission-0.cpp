class Solution {
   public:
    int characterReplacement(string s, int k) {
        int left = 0;
        int maxFrequency = 0;
        int maxLength = 0;
        std::array<int, 26> alphabet{0};
        for (int right = 0; right < s.length(); right++) {
            alphabet[s[right] - 'A']++;
            maxFrequency = std::max(maxFrequency, alphabet[s[right] - 'A']);
            int currentLen = right - left + 1;
            if(currentLen - maxFrequency > k){
                alphabet[s[left] - 'A']--;
                left++;
                currentLen = right - left + 1;
            }
            maxLength = std::max(maxLength, currentLen);
        }
        return maxLength;
    }
};