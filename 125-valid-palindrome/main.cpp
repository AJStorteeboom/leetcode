#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string onlyAlpha;

        for(char x : s) if(isalpha(x) || isdigit(x)) onlyAlpha.push_back(tolower(x));

        stack<char> palindromeStack;
        bool isEvenSize = (onlyAlpha.size()%2==0);

        for(int x = 0; x < onlyAlpha.size(); x++) {
            if(!isEvenSize && x == onlyAlpha.size()/2) {
                continue;
            } else if(x < onlyAlpha.size()/2) {
                palindromeStack.push(onlyAlpha[x]);
            } else {
                if(palindromeStack.top() == onlyAlpha[x]) {
                    palindromeStack.pop();
                } else {
                    cout << palindromeStack.top() << " != " << onlyAlpha[x] << " - x " << x << endl;
                    return false;
                }
            }
        }

        return true;
    }

    bool isPalindrome_s(string s) {
        for(int x = 0, y = s.size()-1; x < s.size() && y > 0; x++, y--) {
            while (x < s.size() && !isalpha(s[x]) && !isdigit(s[x])) x++; //Skip until valid character
            while (y > 0 && !isalpha(s[y]) && !isdigit(s[y])) y--; //Skip until valid character

            if(x >= y) return true; //True because we didn't found any characters that didn't match
            if(tolower(s[x]) != tolower(s[y])) return false; //Not a palindrome if characters don't match
        }

        return true;
    }
};

//a m a n a p l a n a  c  a  nalpanama
//1 2 3 4 5 6 7 8 9 10 11 12

//amanaplana c analpanama
//
int main() {
    Solution sol;

    cout << sol.isPalindrome_s("A man, a plan, a canal: Panama") << endl;

    return 0;
}
