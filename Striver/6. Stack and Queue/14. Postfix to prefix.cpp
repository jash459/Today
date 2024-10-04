Postfix Expression: 23*45-+
Prefix Expression: +*23-45

bool isOperator(char c) {
    if (c == '+' || c == '-' || c == '*' || c == '/') {
        return true;
    }
    return false;
}

string postfixToPrefix(string postfix) {
    stack<string> s;
    int length = postfix.length();
    for (int i = 0; i < length; i++) {
        if (isOperator(postfix[i])) {
            string op2 = s.top();
            s.pop();
            string op1 = s.top();
            s.pop();
            string temp = postfix[i] + op1 + op2;
            s.push(temp);
        } else {
            s.push(string(1, postfix[i]));
        }
    }
    return s.top();
}
