//Function to return the precendence of operators.
// A higher return value indicates a higher order of operations (precedence)
int prec(char c) {
    if (c == '^') 
        return 3; //Exponentiation is evaluated first 
    else if (c == '/' || c == '*')
        return 2; //Multiplication and division are evaluated second
    else if (c == '+' || c == '-')
        return 1; //Addition and subtraction are evaluated last
    else 
        return -1; //Fallback for parentheses or invalid characters
}

//Function to convert an infix math expression to a postfix expression 
void infixToPostfix(string s) {
    int n = s.length();
    stack<char> st; //Stack is used to temporarily hold the operators and '('
    string result; //String used to build the final postfix output

    //Loop through every character in the provided infix string 
    for (int i = 0; i < n; i++) {
        char c = s[i];

        //The character is an operand (letter or a number)
        //Operands always go directly to the output string immediately
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
            result += c;
        }

        //If the character is a left parenthesis
        //Push it onto the stack to mark the beginning of the sub-expression
        else if (c == '(') {
            st.push('(');
        }

        //the character is the right parentheses 
        //this means we have reach the end of the sub-expression
        //so we pop all the operators from the stack to the result until we hit the left "("
        else if (c == ')') {
            while(st.top() != '(') {
                result += st.top();
                st.pop();
            }
            st.pop(); //pop discard the matching '(' from the stack
        }

        //The character is an operator (+ - * / ^)
        //We cannot put the low precedence operator on the top of high precedence operator in the stack
        else {
            //while the stack is not empty pop operators to the result string if 
            //the operator on the stack has greater precedence or equal than the current one
            while (!st.empty() && prec(s[i]) <= prec(st.top())) {
                result += st.top();
                st.pop();
            }
            //once the higher precedence operators are out of the way push the current one in the stack 
            st.push(c);
        }
    }

    //The entire input string has been parsed.
    //Pop any remaining operators left in stack and add them to the result 
    while(!st.empty()) {
        result += st.top();
        st.pop();
    }

    //Print the final calculated expression 
    cout << "Postfix expression: " << result << endl;
}

int main() {
    // Define the infix expression we want to convert
    string exp = "(p+q)*(m-n)";  
    
    cout << "Infix expression: " << exp << endl;
    
    // Call the function to perform the conversion and print the result
    infixToPostfix(exp);  
    
    return 0;
}

TC: O(n)
there is for loop to scan from left to right and while loop nested inside but every single character from the string 
is pushed onto the stack exactly once and popped exactly once.

SC: O(n)
