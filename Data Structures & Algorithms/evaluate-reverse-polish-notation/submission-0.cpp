class Solution {
   public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> myStack;

        for (const auto& s : tokens) {
            if(isOperator(s)){
                int b = myStack.top();
                myStack.pop();
                int a = myStack.top();
                myStack.pop();
                myStack.push(Calculator(a, b, s[0]));
            }else {
                myStack.push(std::stoi(s));
            }

        }
        return myStack.top();
    }
    int Calculator(int a, int b, char op) {
        switch (op) {
            case '+':
                return a + b;

            case '-':
                return a - b;

            case '*':
                return a * b;

            case '/':
                return a / b;
        }
    }
    bool isOperator(const string& var) {
        if (var == "+") {
            return true;
        }
        if (var == "-") {
            return true;
        }
        if (var == "*") {
            return true;
        }
        if (var == "/") {
            return true;
        }
        return false;
    }
};
