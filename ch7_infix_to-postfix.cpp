#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Function to return precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

// Function to check if the character is an operator
bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

// Function to convert infix expression to postfix
string infixToPostfix(const string& infix) {
    stack<char> st; // Stack to keep operators
    string postfix; // Resulting postfix expression

    for (char c : infix) {
        // If operand, add it to the output
        if (isalnum(c)) {
            postfix += c;
        }
        // If '(', push it to the stack
        else if (c == '(') {
            st.push(c);
        }
        // If ')', pop and output from the stack until '(' is found
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            st.pop(); // Remove the '(' from stack
        }
        // If operator, pop operators from stack according to precedence
        else if (isOperator(c)) {
            while (!st.empty() && precedence(st.top()) >= precedence(c)) {
                postfix += st.top();
                st.pop();
            }
            st.push(c); // Push current operator to stack
        }
    }

    // Pop remaining operators from the stack
    while (!st.empty()) {
        if (st.top() == '(') {
            cout << "Invalid expression" << endl;
            return "";
        }
        postfix += st.top();
        st.pop();
    }

    return postfix;
}

int main() {
    string infix = "A+B*(C^D-E)";
    string postfix = infixToPostfix(infix);
    cout << "Infix: " << infix << endl;
    cout << "Postfix: " << postfix << endl;
    return 0;
}
