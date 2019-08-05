#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    stack<char> sp;
    bool isValid(string s) {
        for (int i = 0; s[i]; i++) {
            if (s[i] == '{' || s[i] == '(' || s[i] == '[')
                sp.push(s[i]);
            else {
                if (sp.size() == 0)
                    return false;
                if (s[i] == '}') {
                    char ch = sp.top();
                    if (ch != '{')
                        return false;
                    sp.pop();
                }
                else if (s[i] == ')') {
                    char ch = sp.top();
                    if (ch != '(')
                        return false;
                    sp.pop();
                }
                else if (s[i] == ']') {
                    char ch = sp.top();
                    if (ch != '[')
                        return false;
                    sp.pop();
                }
            }
        }
        return sp.size() == 0;
    }
};