// Last updated: 10/5/2025, 8:56:21 AM
class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> st;

        for (char ch : expression) {
            if (ch == ',') {
                continue;  // Ignore commas as they are just separators
            } else if (ch != ')') {
                st.push(ch);  // Push everything except ')'
            } else {
                // When we encounter ')', we process the expression inside the parentheses
                vector<char> operands;
                // Pop until we reach the matching '('
                while (st.top() != '(') {
                    operands.push_back(st.top());
                    st.pop();
                }
                st.pop();  // Pop the '('

                // The operator will be just before '('
                char op = st.top();
                st.pop();  // Pop the operator as well

                // Now evaluate the expression based on the operator
                bool result;
                if (op == '&') {
                    result = true;
                    for (char operand : operands) {
                        if (operand == 'f') {
                            result = false;
                            break;
                        }
                    }
                } else if (op == '|') {
                    result = false;
                    for (char operand : operands) {
                        if (operand == 't') {
                            result = true;
                            break;
                        }
                    }
                } else if (op == '!') {
                    // There will be only one operand in the case of '!'
                    result = (operands[0] == 'f');
                }

                // Push the result back as 't' or 'f'
                st.push(result ? 't' : 'f');
            }
        }

        // At the end, the stack should contain the final result
        return st.top() == 't';
    }
};
