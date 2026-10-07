class Solution {
   public:
    string mergeAlternately(string word1, string word2) {
        std::string myResult;
        myResult.reserve(word1.length() + word2.length());
        int w1 = 0;
        while (w1 < word1.length() && w1 < word2.length()) {
            myResult.push_back(word1[w1]);
            myResult.push_back(word2[w1]);
            w1++;
        }
        if(word1.length() > word2.length()){
            myResult += word1.substr(w1);
        }else {
            myResult += word2.substr(w1);
        }
        return myResult;
    }
};