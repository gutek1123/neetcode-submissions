class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        std::stack<int> st;
        std::vector<int> res = prices;

        for(int i = prices.size() - 1; i >= 0; i--){
            while(!st.empty() && st.top() > prices[i]){
                st.pop();
            }

            int sale = st.empty() ? 0 : st.top();
            st.push(res[i]);
            res[i] = res[i] - sale;
        }

        return res;
        
    }
};
