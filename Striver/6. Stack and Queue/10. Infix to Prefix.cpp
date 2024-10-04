// Link : https://takeuforward.org/data-structure/infix-to-prefix/

// video :

#include <bits/stdc++.h>

using namespace std;

bool isOperator(char c) {
  return (!isalpha(c) && !isdigit(c));
}

int getPriority(char C) {
  if (C == '-' || C == '+')
    return 1;
  else if (C == '*' || C == '/')
    return 2;
  else if (C == '^')
    return 3;
  return 0;
}

string infixToPostfix(string infix) {
  infix = '(' + infix + ')';
  int l = infix.size();
  stack < char > st;
  string output;

  for (int i = 0; i < l; i++) {

    // If the scanned character is an
    // operand, add it to output.
    if (isalpha(infix[i]) || isdigit(infix[i]))
      output += infix[i];

    // If the scanned character is an
    // ‘(‘, push it to the stack.
    else if (infix[i] == '(')
      st.push('(');

    // If the scanned character is an
    // ‘)’, pop and output from the stack
    // until an ‘(‘ is encountered.
    else if (infix[i] == ')') {
      while (st.top() != '(') {
        output += st.top();
        st.pop();
      }

      // Remove '(' from the stack
      st.pop();
    }

    // Operator found
    else {
      if (isOperator(st.top())) {
        if (infix[i] == '^') {
          while (getPriority(infix[i]) <= getPriority(st.top())) {
            output += st.top();
            st.pop();
          }

        } else {
          while (getPriority(infix[i]) < getPriority(st.top())) {
            output += st.top();
            st.pop();
          }

        }

        // Push current Operator on stack
        st.push(infix[i]);
      }
    }
  }
  while (!st.empty()) {
    output += st.top();
    st.pop();
  }
  return output;
}

string infixToPrefix(string infix) {
  /* Reverse String
    Replace ( with ) and vice versa
    Get Postfix
    Reverse Postfix  */
  int l = infix.size();

  // Reverse infix
  reverse(infix.begin(), infix.end());

  // Replace ( with ) and vice versa
  for (int i = 0; i < l; i++) {

    if (infix[i] == '(') {
      infix[i] = ')';
      i++;
    } else if (infix[i] == ')') {
      infix[i] = '(';
      i++;
    }
  }

  string prefix = infixToPostfix(infix);

  // Reverse postfix
  reverse(prefix.begin(), prefix.end());

  return prefix;
}

int main() {
  string s = ("(p+q)*(c-d)");
  cout << "Infix expression: " << s << endl;
  cout << "Prefix Expression: " << infixToPrefix(s) << endl;
  return 0;
}

// Output:

// Infix expression: (p+q)*(c-d)
// Prefix Expression: *+pq-cd

// Time Complexity: O(N)

// Space Complexity: O(N)