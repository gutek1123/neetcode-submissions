class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int longestCommonPart = 0;
        char expectedCharacter = strs[0][0];

        size_t shortestS = INT_MAX;
        for(const auto& s : strs){
            shortestS = std::min(shortestS, s.length());
        }

        for(int i = 0; i < shortestS;i++){
            for(int j = 0; j < strs.size() - 1; j++){
                if(strs[j][i] != strs[j + 1][i]){
                    return strs[j].substr(0, longestCommonPart);
                }
            }
            longestCommonPart++;
        }
        return strs[0].substr(0, shortestS);
    }
};