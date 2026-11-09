class Solution {
   public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) {
            return false;
        }

        std::array<int, 26> s1Arr{0};

        std::array<int, 26> s2Arr{0};

        for (const auto& c : s1) {
            s1Arr[c - 'a']++;
        }

        for (int i = 0; i < s1.length(); i++) {
            s2Arr[s2[i] - 'a']++;
        }

        if(s1Arr == s2Arr){
            return true;
        }

        for(int i = s1.length(); i < s2.length(); i++){
            s2Arr[s2[i-s1.length()]- 'a']--;
            s2Arr[s2[i]-'a']++;
            if(s1Arr == s2Arr){
                return true;
            }
        }
        return false;
    }
};
