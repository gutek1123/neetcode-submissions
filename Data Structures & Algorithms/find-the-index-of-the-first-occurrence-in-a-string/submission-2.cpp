class Solution {
public:
    int strStr(string haystack, string needle) {
        for(std::size_t i = 0; i <= haystack.length() - needle.length(); i++){
            for(std::size_t j = i; j < i + needle.length(); j++){
                
                if(j - i == needle.length() - 1 && haystack[j] == needle[j-i]){
                    return i;
                }

                if(haystack[j] != needle[j - i]){
                    break;
                }

            }
        }
        return -1;
    }
};