#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Function to convert a prefix expression to a postfix expression
string prefixToPostfix(string prefix) {
    stack<string> s; // Stack stores complete sub-expressions as strings
    int n = prefix.size();

    // Traverse the prefix expression character by character from RIGHT to LEFT
    for (int i = n - 1; i >= 0; i--) {
        char c = prefix[i];

        // CASE 1: The character is an operand (letter or number)
        // Rule: Push it directly onto the stack as a string.
        if (isalnum(c)) {
            s.push(string(1, c)); 
        } 
        
        // CASE 2: The character is an operator (+, -, *, /, etc.)
        else {
            // Rule: Pop two operands from the stack.
            // NOTE: Because we are reading right-to-left (Prefix), the top of the 
            // stack is the LEFT operand, and the next item down is the RIGHT operand.
            string op1 = s.top(); // Left operand
            s.pop();
            
            string op2 = s.top(); // Right operand
            s.pop();

            // Form the new POSTFIX expression.
            // Postfix order: Left Operand, then Right Operand, followed by the Operator
            string temp = op1 + op2 + c;
            
            // Push the newly formed postfix sub-expression back onto the stack
            s.push(temp);
        }
    }

    // After traversing the whole string, the single remaining element 
    // in the stack is the fully constructed postfix expression.
    return s.top();
}

int main() {
    // Prefix expression to convert (same example from the previous conversion, reversed)
    string prefix = "*-A/BC-/AKL";
    
    cout << "Prefix Expression: " << prefix << endl;
    cout << "Postfix Expression: " << prefixToPostfix(prefix) << endl;
    
    return 0;
}

Output: 
Prefix Expression: *-A/BC-/AKL
Postfix Expression: ABC/-AK/L-*

TC: O(n)
SC: O(n)

