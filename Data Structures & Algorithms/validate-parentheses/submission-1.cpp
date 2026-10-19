class Solution {
public:
    bool isValid(string s) {
        std::stack<char> st;

        for(const char& c : s){
            if(isOpeningBracket(c)){
                st.push(c);
            }else if(isClosingBracket(c)){
                if(st.empty()){
                    return false;
                }
                if(!areBracketsCompatible(st.top(), c)){
                    return false;
                }
                st.pop();
            }
        }

        return st.empty();

    }
    bool isOpeningBracket(const char c){
        return c == '[' || c == '{' || c == '(';
    }
    bool isClosingBracket(const char c){
        return c == ']' || c == '}' || c == ')';
    }
    bool areBracketsCompatible(const char c1, const char c2){
        if(c1 == '('){
            return c2 == ')';
        }

        if(c1 == '{'){
            return c2 == '}';
        }

        if(c1 == '['){
            return c2 == ']';
        }
        return false;
    }

};
