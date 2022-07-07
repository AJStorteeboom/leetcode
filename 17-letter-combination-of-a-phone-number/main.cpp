#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    unordered_map<char, vector<char>> digitToChar;
    string digits;
    int totalDigits;
    vector<string> result;

    void backtrack(int currentDigit, string currentString) {
        cout << currentDigit << " - " << currentString << endl;
        if (currentDigit == totalDigits) {
            result.push_back(currentString);
            return;
        }

        string currentStringCopy = currentString;
        for (char digitChar: digitToChar[digits[currentDigit]]) {
            currentString += digitChar;
            backtrack(currentDigit + 1, currentString);
            currentString = currentStringCopy;
        }
    }

    vector<string> letterCombinations(string digits) {
        this->digits = digits;
        this->totalDigits = digits.size();

        digitToChar.insert({'2', {'a', 'b', 'c'}});
        digitToChar.insert({'3', {'d', 'e', 'f'}});
        digitToChar.insert({'4', {'g', 'h', 'i'}});
        digitToChar.insert({'5', {'j', 'k', 'l'}});
        digitToChar.insert({'6', {'m', 'n', 'o'}});
        digitToChar.insert({'7', {'p', 'q', 'r', 's'}});
        digitToChar.insert({'8', {'t', 'u', 'v'}});
        digitToChar.insert({'9', {'w', 'x', 'y', 'z'}});

        backtrack(0, "");

        return result;
    }
};

int main() {
    Solution sol;

    cout << sol.letterCombinations("23").size() << endl;

    std::cout << "" << std::endl;
    return 0;
}
