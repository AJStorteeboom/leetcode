#include <iostream>

#include <stack>

using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> openParenthesesStack;

        string result;

        for (int x = 0; x < s.length(); x++) {
            if (s[x] != '(' && s[x] != ')') {
                result.push_back(s[x]);
                continue;
            }

            if (s[x] == ')' && !openParenthesesStack.empty()) {
                openParenthesesStack.pop();
                result.push_back(')');
            } else if (s[x] == '(') {
                result.push_back('(');
                openParenthesesStack.push(result.size() - 1);
            }
        }

        while (!openParenthesesStack.empty()) {
            result.erase(openParenthesesStack.top(), 1);
            openParenthesesStack.pop();
        }

        return result;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
