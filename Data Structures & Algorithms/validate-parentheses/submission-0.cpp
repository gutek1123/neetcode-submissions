class Solution {
   public:
    bool isValid(string s) {
        std::stack<char> st;
        for (char c : s) {
            if (isOpeningBracket(c)) {
                st.push(c);
            } else if (isClosingBracket(c)) {
                if (st.empty()) {
                    return false;
                }
                if (!areBracketsCompatible(st.top(), c)) {
                    return false;
                }
                st.pop();
            }
        }
        return st.empty();
    }

    bool isOpeningBracket(char c) {
        if (c == '(' || c == '{' || c == '[') {
            return true;
        }
        return false;
    }

    bool isClosingBracket(char c) {
        if (c == ')' || c == '}' || c == ']') {
            return true;
        }
        return false;
    }

    bool areBracketsCompatible(char opening, char closing) {
        switch (opening) {
            case '(':
                return closing == ')';

            case '{':
                return closing == '}';

            case '[':
                return closing == ']';

            default:
                return false;
        }
    }
};
