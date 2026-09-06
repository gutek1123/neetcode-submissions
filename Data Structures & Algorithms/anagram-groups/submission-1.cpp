class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<std::string, int> myMap;
        std::vector<std::vector<std::string>> myResult;
        for (int i = 0; i < strs.size(); i++) {
            std::string myCurrentString = strs[i];
            std::sort(myCurrentString.begin(), myCurrentString.end());

            if (auto it = myMap.find(myCurrentString); it == myMap.end()) {
                myMap.insert({myCurrentString, myResult.size()});
                myResult.push_back({strs[i]});
            } else {
                myResult[it->second].push_back(strs[i]);
            }
        }
        return myResult;
    }
};
