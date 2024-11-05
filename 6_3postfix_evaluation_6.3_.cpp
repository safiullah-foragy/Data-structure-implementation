#include<bits/stdc++.h>


using namespace std;

int evaluatePostfix(const string &expression) {
    stack<int> stk;
    stringstream ss(expression);
    string token;

    while (ss >> token) {
           if (isdigit(token[0])) {
            
            stk.push(stoi(token));
        } else {
            
            int A = stk.top(); stk.pop();
            int B = stk.top(); stk.pop();
            int result;

            switch (token[0]) {
                case '+': result = B + A; break;
                case '-': result = B - A; break;
                case '*': result = B * A; break;
                case '/': result = B / A; break;
                default: throw invalid_argument("Unknown operator");
            }

            
            stk.push(result);
        }
    }

    
    return stk.top();
}

int main() {
    string postfixExpression = "5 6 2 + * 12 4 / -";

    cout << "The result of the postfix expression is: " << evaluatePostfix(postfixExpression) << endl;
    return 0;
}

