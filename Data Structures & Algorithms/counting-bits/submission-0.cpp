class Solution {
public:
    vector<int> countBits(int n) {
        std::vector<int> myAnswer(n + 1, 0);

        for(int i = 1; i <= n; i++){
            myAnswer[i] = myAnswer[i & (i - 1)] + 1;
        }

        return myAnswer;
    }
};
