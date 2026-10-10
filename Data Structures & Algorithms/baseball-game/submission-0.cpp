class Solution {
public:
    int calPoints(vector<string>& operations) {
        std::stack<int> score;
        for(const auto& s : operations){
            if(s == "C"){
                score.pop();
            }else if(s == "+"){
                int score1 = score.top();
                score.pop();
                int score2 = score1 + score.top();
                score.push(score1);
                score.push(score2);
            }else if(s == "D"){
                score.push(score.top() * 2);
            }else {
                score.push(std::stoi(s));
            }
        }
        int totalScore = 0;
        while(!score.empty()){
            totalScore += score.top();
            score.pop();
        }
        return totalScore;
    }
};