//Function to convert a postfix expression to an infix expression
string postfixToInfix(string postfix) {
    stack<string> s; //stack stores strings (complete sub-expressions) not just characters 
    int n = postfix.size();

    //Traverse the postfix expression character by character from left to right 
    for (int i = 0; i < n; i++) {
        char c = postfix[i];

        //The character is an operand (char or num)
        //Push it directly onto the stack as a string 
        if (isalnum(c)) {
            //Convert the character to a string of length 1 and push it 
            s.push(string(1, c));
        }

        //The char is operator 
        else {
            string op2 = s.top();
            s.pop();

            string op1 = s.top();
            s.pop();

            string temp = "(" + op1  + c + op2 + ")";

            //Push the newly formed sub-expression back onto the stack
            s.push(temp);
        }
    }

    //After the loop the final element remaining in the stack is the complete infix expression
    return s.top();

}

int main() {
    // Postfix expression to evaluate
    string postfix = "AB*C+";
    
    // Output the result
    cout << "Postfix Expression: " << postfix << endl;
    cout << "Infix Expression: " << postfixToInfix(postfix) << endl;
    
    return 0;
}

TC: O(n) to O(n^2)
SC: O(n)