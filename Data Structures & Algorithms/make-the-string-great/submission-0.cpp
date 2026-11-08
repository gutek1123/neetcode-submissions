class Solution {
public:
    string makeGood(string s) {
        std::string res = "";

        for(const auto& c : s){
            if(!res.empty() && std::abs(res.back() - c) == 'a' - 'A'){
                res.pop_back();
            }else {
                res.push_back(c);
            }
        }
        return res;
    }
};
