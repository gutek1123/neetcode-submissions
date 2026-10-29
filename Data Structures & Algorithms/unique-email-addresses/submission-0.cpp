class Solution {
   public:
    int numUniqueEmails(vector<string>& emails) {
        std::unordered_set<std::string> uniqueEmails;
        uniqueEmails.reserve(emails.size());
        for (const auto& email : emails) {
            uniqueEmails.insert(ParseEmail(email));
        }
        return uniqueEmails.size();
    }
    std::string ParseEmail(const std::string& myString) {
        std::size_t counter = 0;
        std::string res;
        res.reserve(myString.size());
        while (counter < myString.length() && myString[counter] != '@') {
            if (myString[counter] == '+') {
                break;
            }

            if (myString[counter] != '.') {
                res.push_back(myString[counter]);
            }
            counter++;
        }

        auto atPosition = myString.find('@');

        res += myString.substr(atPosition);

        return res;
    }
};