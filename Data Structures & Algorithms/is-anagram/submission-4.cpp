class Solution {
   public:
    bool isAnagram(string s, string t) {
        std::vector<unsigned int> s1(26, 0);
        std::vector<unsigned int> s2(26, 0);

        if (s.length() != t.length()) {
            return false;
        }

        for (int i = 0; i < s.length(); i++) {
            s1[s[i] - 'a']++;
            s2[t[i] - 'a']++;
        }

        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) {
                return false;
            }
        }
        return true;
    }
};
