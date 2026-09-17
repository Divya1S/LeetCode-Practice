string prefixToInfix(string prefix) {
    stack<string> s; //Stack stores complete sub-expression as strings 
    int n = prefix.size();

    //Loop through the prefix expression from Right to Left 
    for (int i = n - 1; i >= 0; i--) {
        char c = prefix[i];

        //If the character is an operand push it directly onto the stack 
        if (isalnum(c)) {
            //Convert the char to a string and push to stack
            s.push(string(1, c));
        }
        else {
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();

            //Wrap the operands and operator in parentheses 
            string temp = "(" + op1 + c + op2 + ")";

            //Push the newly formed infix sub-expression back onto the stack
            s.push(temp);
        }
    }
    //After traversing the whole string the single remaining element in the stack is the fully constructed infix expression
    return s.top();
}

int main() {
    // Prefix expression to convert
    string prefix = "*-A/BC-/AKL";
    
    cout << "Prefix Expression: " << prefix << endl;
    cout << "Infix Expression: " << prefixToInfix(prefix) << endl;
    
    return 0;
}

Output: 
Prefix Expression: *-A/BC-/AKL
Infix Expression: ((A-(B/C))*((A/K)-L))

TC: O(N)
N is len of prefix expression 
Here heavy string concatenations can technically push the absolute worst-case time complexity closer to O(n^2)
if the expressions are massive long but it is classified as O(n) in algorithmic interviews.

SC: O(n)
n is the length of the prefix expression.
