#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;


class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> visited;
        unordered_set<string> deadendsSet;
        queue<string> queue;
        queue.push("0000");

        for(const string& deadEnd : deadends) {
            if(deadEnd == "0000") return -1;
            deadendsSet.insert(deadEnd);
        }

        int steps = 0;

        while (!queue.empty()) {
            int currentQueueSize = queue.size();

            for(int x = 0; x < currentQueueSize; x++) {
                string currentCode = queue.front();
                queue.pop();

                if(currentCode == target) return steps;

                string copyCurrentCode = currentCode;
                copyCurrentCode[0] = minChar(currentCode[0]);
                if(visited.find(copyCurrentCode) == visited.end() && deadendsSet.find(copyCurrentCode) == deadendsSet.end()) {
                    queue.push(copyCurrentCode);
                    visited.insert(copyCurrentCode);
                }

                copyCurrentCode = currentCode;
                copyCurrentCode[0] = plusChar(currentCode[0]);
                if(visited.find(copyCurrentCode) == visited.end() && deadendsSet.find(copyCurrentCode) == deadendsSet.end()) {
                    queue.push(copyCurrentCode);
                    visited.insert(copyCurrentCode);
                }

                copyCurrentCode = currentCode;
                copyCurrentCode[1] = minChar(currentCode[1]);
                if(visited.find(copyCurrentCode) == visited.end() && deadendsSet.find(copyCurrentCode) == deadendsSet.end()) {
                    queue.push(copyCurrentCode);
                    visited.insert(copyCurrentCode);
                }

                copyCurrentCode = currentCode;
                copyCurrentCode[1] = plusChar(currentCode[1]);
                if(visited.find(copyCurrentCode) == visited.end() && deadendsSet.find(copyCurrentCode) == deadendsSet.end()) {
                    queue.push(copyCurrentCode);
                    visited.insert(copyCurrentCode);
                }

                copyCurrentCode = currentCode;
                copyCurrentCode[2] = minChar(currentCode[2]);
                if(visited.find(copyCurrentCode) == visited.end() && deadendsSet.find(copyCurrentCode) == deadendsSet.end()) {
                    queue.push(copyCurrentCode);
                    visited.insert(copyCurrentCode);
                }

                copyCurrentCode = currentCode;
                copyCurrentCode[2] = plusChar(currentCode[2]);
                if(visited.find(copyCurrentCode) == visited.end() && deadendsSet.find(copyCurrentCode) == deadendsSet.end()) {
                    queue.push(copyCurrentCode);
                    visited.insert(copyCurrentCode);
                }

                copyCurrentCode = currentCode;
                copyCurrentCode[3] = minChar(currentCode[3]);
                if(visited.find(copyCurrentCode) == visited.end() && deadendsSet.find(copyCurrentCode) == deadendsSet.end()) {
                    queue.push(copyCurrentCode);
                    visited.insert(copyCurrentCode);
                }

                copyCurrentCode = currentCode;
                copyCurrentCode[3] = plusChar(currentCode[3]);
                if(visited.find(copyCurrentCode) == visited.end() && deadendsSet.find(copyCurrentCode) == deadendsSet.end()) {
                    queue.push(copyCurrentCode);
                    visited.insert(copyCurrentCode);
                }
            }

            steps++;
        }

        return -1;
    }

    char plusChar(char x) {
        int intValue = x-48;
        if(intValue == 9) return '0';
        int charValue = intValue+49; //+48 ascii table + 1
        return (char) charValue;
    }

    char minChar(char x) {
        int intValue = x-48;
        if(intValue == 0) return '9';
        int charValue = intValue+47; //+48 ascii table - 1
        return (char) charValue;
    }
};

int main() {
    Solution sol;

    vector<string> deadends = {"9990"};

    std::cout << sol.openLock(deadends, "9999") << std::endl;
    return 0;
}
