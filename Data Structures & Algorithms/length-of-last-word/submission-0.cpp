class Solution {
   public:
    int lengthOfLastWord(string s) {
        bool didGetLetter = false;

        int firstCorrectLetterPosition = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            if (didGetLetter && s[i] == ' ') {
                firstCorrectLetterPosition = i + 1;
                break;
            }
            if (!didGetLetter && std::isalnum(s[i])) {
                didGetLetter = true;
            }
        }
        for (int i = firstCorrectLetterPosition; i < s.length(); i++) {
            if (s[i] == ' ') {
                return i - firstCorrectLetterPosition;
            }
        }
        return s.length() - firstCorrectLetterPosition;
    }
};