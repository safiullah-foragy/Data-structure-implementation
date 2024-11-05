#include <iostream>
#include <stack>
#include <string>
#include <cctype>

using namespace std;

// Function to perform an operation and return the result
int performOperation(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        default: return 0; // Just in case of an unknown operator
    }
}

// Function to evaluate a postfix expression
int evaluatePostfix(const string& expression) {
    stack<int> s;

    // Loop through each character in the expression
    for (char ch : expression) {
        if (isdigit(ch)) {
            // If the character is a digit, push it onto the stack
            s.push(ch - '0'); // Convert character to integer
        } else {
            // The character is an operator
            int a = s.top(); s.pop(); // Pop the top two elements
            int b = s.top(); s.pop();
            int result = performOperation(b, a, ch); // Perform the operation
            s.push(result); // Push the result back onto the stack
        }
    }

    // The final result will be the only element left on the stack
    return s.top();
}

int main() {
    string postfixExpression = "53+82-*"; // Example postfix expression
    cout << "The result of the postfix expression is: " << evaluatePostfix(postfixExpression) << endl;
    return 0;
}
