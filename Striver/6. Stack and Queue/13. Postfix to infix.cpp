Postfix Expression: 23*45-+
Infix Expression: (2*3)+(4-5)

bool isOperator(char c) {
    if (c == '+' || c == '-' || c == '*' || c == '/') {
        return true;
    }
    return false;
}

string postfixToInfix(string postfix) {
    stack<string> s;
    int length = postfix.length();
    for (int i = 0; i < length; i++) {
        if (isOperator(postfix[i])) {
            string op2 = s.top();
            s.pop();
            string op1 = s.top();
            s.pop();
            string temp = "(" + op1 + postfix[i] + op2 + ")";
            s.push(temp);
        } else {
            s.push(string(1, postfix[i]));
        }
    }
    return s.top();
}

