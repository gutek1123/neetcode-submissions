class Solution {
   public:
    string minWindow(string s, string t) {
        std::array<int, 128> neededCharacters{0};
        for (const char& tt : t) {
            neededCharacters[tt]++;
        }

        int need = 0;
        for (int i = 0; i < neededCharacters.size(); i++) {
            if (neededCharacters[i] > 0) {
                need++;
            }
        }

        std::array<int, 128> havingCharacters{0};

        int left = 0;
        int have = 0;

        int shortestWindowBegin = 0;
        int shortestWindowLen = INT_MAX;

        for (int right = 0; right < s.length(); right++) {
            havingCharacters[s[right]]++;

            if (havingCharacters[s[right]] == neededCharacters[s[right]]) {
                have++;
            }

            while(have >= need){
                int len = right - left + 1;
                if(len < shortestWindowLen){
                    shortestWindowLen = len;
                    shortestWindowBegin = left;
                }
                
                havingCharacters[s[left]]--;
                if(havingCharacters[s[left]] < neededCharacters[s[left]]){
                    have--;
                }
                left++;

            }
        }
        if(shortestWindowLen == INT_MAX){
            return "";
        }
        return s.substr(shortestWindowBegin, shortestWindowLen);
    }
};
