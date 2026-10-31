class Solution {
   public:
    vector<string> stringMatching(vector<string>& words) {
        std::sort(words.begin(), words.end(), [](const std::string& s1, const std::string& s2) {
            return s1.length() < s2.length();
        });

        std::vector<std::string> res;

        for (std::size_t i = 0; i < words.size(); i++) {
            for(std::size_t j = 0; j < i; j++){
                std::string::size_type n = words[i].find(words[j]);
                
                if(n == std::string::npos){
                    continue;
                }

                if(auto it = std::find(res.begin(), res.end(), words[j]); it == res.end()){
                    res.push_back(words[j]);
                }

            }
        }
        return res;
    }
};