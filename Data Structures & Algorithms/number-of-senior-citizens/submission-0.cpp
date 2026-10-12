class Solution {
public:
    int countSeniors(vector<string>& details) {
        int seniorCounter = 0;
        for(const auto& s : details){
            int age = std::stoi(s.substr(11, 2));
            if(age > 60){
                seniorCounter++;
            }
        }
        return seniorCounter;
    }
};