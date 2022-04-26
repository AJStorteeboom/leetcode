#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        int mem[101] = {0};

        //Store perfect squares up to 10.000;
        for(int x = 1; x <= 100; x++) mem[x] = x*x;

        unordered_set<int> visited;
        queue<int> queue;
        queue.push(n);

        int currentSquares = 0;

        //BFS on the current value.
        while (!queue.empty()) {
            int queueSize = queue.size();

            for(int x = 0; x < queueSize; x++) {
                int front = queue.front();
                queue.pop();

                for(int y = 100; y >= 1; y--) {
                    if(mem[y] > front || visited.find(front-mem[y]) != visited.end()) continue;
                    if(mem[y] == front) return currentSquares+1;

                    visited.insert(front-mem[y]);
                    queue.push(front-mem[y]);
                }
            }

            currentSquares++;
        }

        return -1;
    }
};


int main() {
    Solution sol;

    std::cout << sol.numSquares(3) << std::endl;
    return 0;
}
