class Solution {
public:
    int scoreOfString(string s) {
        uint32_t result = 0;
        for(std::size_t i = s.length() - 1; i >= 1; i--){
            result += abs(s[i] - s[i-1]);
        }
        return result;
    }
};