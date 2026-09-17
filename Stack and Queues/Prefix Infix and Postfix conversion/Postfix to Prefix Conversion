#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Function to convert a postfix expression to a prefix expression
string postfixToPrefix(string postfix) {
    stack<string> s; // Stack stores complete sub-expressions as strings
    int n = postfix.size();

    // Traverse the postfix expression character by character from LEFT to RIGHT
    for (int i = 0; i < n; i++) {
        char c = postfix[i];

        // CASE 1: The character is an operand (letter or number)
        // Rule: Push it directly onto the stack as a string.
        if (isalnum(c)) {
            s.push(string(1, c)); 
        } 
        
        // CASE 2: The character is an operator (+, -, *, /, etc.)
        else {
            // Rule: Pop two operands from the stack.
            // NOTE: Because we are reading left-to-right (Postfix), the first 
            // pop gets the RIGHT operand, and the second pop gets the LEFT operand.
            string op2 = s.top(); // Right operand
            s.pop();
            
            string op1 = s.top(); // Left operand
            s.pop();

            // Form the new PREFIX expression.
            // Prefix order: Operator followed by Left Operand, then Right Operand
            string temp = c + op1 + op2;
            
            // Push the newly formed prefix sub-expression back onto the stack
            s.push(temp);
        }
    }

    // After traversing the whole string, the single remaining element 
    // in the stack is the fully constructed prefix expression.
    return s.top();
}

int main() {
    // Postfix expression to convert
    string postfix = "ABC/-AK/L-*";
    
    cout << "Postfix Expression: " << postfix << endl;
    cout << "Prefix Expression: " << postfixToPrefix(postfix) << endl;
    
    return 0;
}

Output
Postfix Expression: ABC/-AK/L-*
Prefix Expression: *-A/BC-/AKL

TC: O(N)

SC: O(N)