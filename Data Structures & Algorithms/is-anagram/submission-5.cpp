class Solution {
   public:
    bool isAnagram(string s, string t) {
        std::array<int,26> sArr{0};
        std::array<int,26> tArr{0};

        if (s.length() != t.length()) {
            return false;
        }

        for (std::size_t i = 0; i < s.length(); i++) {
            sArr[s[i] - 'a']++;
            tArr[t[i]- 'a']++;
        }

        return sArr == tArr;
    }
};
