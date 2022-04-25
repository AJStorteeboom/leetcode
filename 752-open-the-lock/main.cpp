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

        for(const string& deadEnd : deadends) {
            if(deadEnd == "0000") return -1;
            deadendsSet.insert(deadEnd);
        }

        queue<string> queue;
        queue.push("0000");
        int steps = 0;

        while (!queue.empty()) {
            int currentQueueSize = queue.size();

            for(int x = 0; x < currentQueueSize; x++) {
                string currentCode = queue.front();
                queue.pop();

                if(currentCode == target) return steps;

                for(int y = 0; y < 4; y++) {
                    string copyCurrentCode = currentCode;
                    copyCurrentCode[y] = minChar(currentCode[y]);

                    if(visited.find(copyCurrentCode) == visited.end() && deadendsSet.find(copyCurrentCode) == deadendsSet.end()) {
                        queue.push(copyCurrentCode);
                        visited.insert(copyCurrentCode);
                    }

                    copyCurrentCode = currentCode;
                    copyCurrentCode[y] = plusChar(currentCode[y]);

                    if(visited.find(copyCurrentCode) == visited.end() && deadendsSet.find(copyCurrentCode) == deadendsSet.end()) {
                        queue.push(copyCurrentCode);
                        visited.insert(copyCurrentCode);
                    }
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
