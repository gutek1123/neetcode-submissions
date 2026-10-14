class Solution {
   public:
    int minOperations(vector<string>& logs) {
        std::stack<bool> st;

        for (const auto& s : logs) {
            if (s == "../") {
                if (!st.empty()) {
                    st.pop();
                }
            } else if (s == "./") {
            } else {
                st.push(true);
            }
        }
        return st.size();
    }
};