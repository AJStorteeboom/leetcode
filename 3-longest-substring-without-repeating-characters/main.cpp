#include <iostream>

using namespace std;

#include <unordered_set>


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0) return 0;

        unordered_set<char> currentSubstring = {s[0]};
        int maxLength = 1;

        int i = 0;
        for (int j = 1; j < s.size(); j++) {
            while (currentSubstring.find(s[j]) != currentSubstring.end()) {
                currentSubstring.erase(s[i]);
                i++;
            }

            currentSubstring.insert(s[j]);
            maxLength = max(maxLength, (int) currentSubstring.size());
        }

        return maxLength;
    }
};

int lengthOfLongestSubstring(string s) {
    int aPointer = 0;
    int bPointer = 0;
    int currentMaxlength = 0;

    unordered_set<char> memory;

    while (bPointer < s.length()) {
        if (memory.find(s[bPointer]) == memory.end()) {
            memory.insert(s[bPointer]);
            bPointer++;
            currentMaxlength = max((int) memory.size(), currentMaxlength);
        } else {
            memory.erase(s[aPointer]);
            aPointer++;
        }
    }

    return currentMaxlength;
}


int main() {
    Solution sol;


    cout << sol.lengthOfLongestSubstring("pwwkew") << endl;

    return 0;
}






