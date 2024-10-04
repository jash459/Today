Prefix Expression: +*23-45
Postfix Expression: 23*45-+

bool isOperator(char c) {
    if (c == '+' || c == '-' || c == '*' || c == '/') {
        return true;
    }
    return false;
}

string prefixToPostfix(string prefix) {
    stack<string> s;
    int length = prefix.length();
    for (int i = length - 1; i >= 0; i--) {
        if (isOperator(prefix[i])) {
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();
            string temp = op1 + op2 + prefix[i];
            s.push(temp);
        } else {
            s.push(string(1, prefix[i]));
        }
    }
    return s.top();
}
