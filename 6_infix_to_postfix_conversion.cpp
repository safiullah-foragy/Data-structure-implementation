#include <bits/stdc++.h>


using namespace std;

// Function to return precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    } else if (op == '*' || op == '/') {
        return 2;
    } else if (op == '^') {
        return 3;
    } else {
        return 0;
    }
}

// Function to check if a character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Function to convert infix expression to postfix
string infixToPostfix(string infix) {
    stack<char> s;
    string postfix = "";

    // Add '(' to the beginning and ')' to the end of the infix expression
    infix = '(' + infix + ')';

    for (char ch : infix) {
        if (isalnum(ch)) {
            // If the character is an operand, add it to postfix expression
            postfix += ch;
        } else if (ch == '(') {
            // If the character is '(', push it to the stack
            s.push(ch);
        } else if (ch == ')') {
            // If the character is ')', pop and output from the stack until '(' is found
            while (s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            s.pop(); // Pop the '(' from the stack
        } else if (isOperator(ch)) {
            // If the character is an operator
            while (!s.empty() && precedence(ch) <= precedence(s.top())) {
                postfix += s.top();
                s.pop();
            }
            s.push(ch);
        }
    }
    return postfix;
}

int main() {
    // string infix = "A+B*(C^D-E)^(F+G*H)-I";
     string infix = "A+(B*C-(D/E^F)*G)*H";
    string postfix = infixToPostfix(infix);

    cout << "Infix Expression: " << infix << endl<<endl;
    cout << "Postfix Expression: " << postfix << endl;

    return 0;
}
