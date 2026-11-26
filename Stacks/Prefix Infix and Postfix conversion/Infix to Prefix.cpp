#include <iostream>
#include <stack>
#include <algorithm> // Required for std::reverse
#include <string>
using namespace std;

// Helper function to return operator precedence
int prec(char c) {
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

// Function to convert an infix expression to a prefix expression
string infixToPrefix(string s) {
    // STEP 1: Reverse the original infix expression
    reverse(s.begin(), s.end());

    // STEP 2: Swap '(' and ')' since the string is backwards
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            s[i] = ')';
        } else if (s[i] == ')') {
            s[i] = '(';
        }
    }

    stack<char> st;
    string result;

    // STEP 3: Apply the Infix-to-Postfix algorithm on the reversed string
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];

        // If operand, add directly to result
        if (isalnum(c)) {
            result += c;
        } 
        // If '(', push to stack
        else if (c == '(') {
            st.push('(');
        } 
        // If ')', pop until we find the matching '('
        else if (c == ')') {
            while (st.top() != '(') {
                result += st.top();
                st.pop();
            }
            st.pop();
        } 
        // If operator
        else {
            // THE TWEAK: Because the string is reversed, operator associativity flips!
            // For standard left-associative operators (+, -, *, /), we now pop ONLY 
            // if the stack top has strictly GREATER precedence (c < st.top()).
            if (c == '+' || c == '-' || c == '*' || c == '/') {
                while (!st.empty() && prec(c) < prec(st.top())) {
                    result += st.top();
                    st.pop();
                }
            } 
            // For right-associative operators (^), we pop if the stack top has 
            // GREATER OR EQUAL precedence (c <= st.top()).
            else if (c == '^') {
                while (!st.empty() && prec(c) <= prec(st.top())) {
                    result += st.top();
                    st.pop();
                }
            }
            st.push(c);
        }
    }

    // Pop any remaining operators from the stack
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }

    // STEP 4: Reverse the resulting postfix string to get the true prefix expression
    reverse(result.begin(), result.end());

    return result;
}

int main() {
    // Complex infix expression to test the conversion
    string exp = "(A+B)*C-(D-E)*(F+G)";
    
    cout << "Infix Expression: " << exp << endl;
    cout << "Prefix Expression: " << infixToPrefix(exp) << endl;
    
    return 0;
}

Output: 
Infix Expression: (A+B)*C-(D-E)*(F+G)
Prefix Expression: -*+ABC*-DE+FG

TC: O(n)
SC: O(n)