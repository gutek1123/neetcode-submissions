class Solution {
   public:
    bool isSubsequence(string s, string t) {
        std::size_t subCharacter = 0;

        for (std::size_t i = 0; i < t.length(); i++) {
  
            if(t[i] == s[subCharacter]){
                subCharacter++;
            }
  
            if (subCharacter == s.length()) {
                return true;
            }
        }
        return false;
    }
};