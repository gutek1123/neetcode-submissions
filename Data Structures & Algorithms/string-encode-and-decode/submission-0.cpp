class Solution {
   public:
    string encode(vector<string>& strs) {
        std::string result = "";
        for (const auto& s : strs) {
            result += std::to_string(s.size()) + divider + s;
        }
        return result;
    }

    vector<string> decode(string s) {
        std::vector<string> result;
        std::size_t counter = 0;
        std::size_t counterBegin = 0;
        std::size_t sizeOfS = s.length();
        int number = 0;
        while (counter < sizeOfS) {
            if (s[counter] == divider) {
                number = std::stoi(s.substr(counterBegin, counter - counterBegin));
                counter++;
                result.emplace_back(s.substr(counter, number));
                counter += number;
                counterBegin = counter;
            } else {
                counter++;
            }
        }
        return result;
    }

   private:
    const char divider = '$ ';
};