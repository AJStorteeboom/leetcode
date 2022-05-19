#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

class Solution {
public:

    int memo[201][201] = {0};


    int longestIncreasingPath(vector<vector<int>> &matrix) {
        int longestPath = 0;

        for (int x = 0; x < matrix.size(); x++) {
            for (int y = 0; y < matrix[x].size(); y++) {
                if (memo[x][y] != 0) continue;

                stack<pair<int, int>> posStack;
                posStack.push(pair<int, int>(x, y));


                while (!posStack.empty()) {
                    pair<int, int> pos = posStack.top();

                    int maxNeighbors = 0;

                    if (pos.first > 0 && matrix[pos.first - 1][pos.second] < matrix[pos.first][pos.second]) {
                        if (memo[pos.first - 1][pos.second] == 0) {
                            posStack.push(pair<int, int>(pos.first - 1, pos.second));
                            continue;
                        } else {
                            maxNeighbors = memo[pos.first - 1][pos.second];
                        }
                    }

                    if (pos.second > 0 && matrix[pos.first][pos.second - 1] < matrix[pos.first][pos.second]) {
                        if (memo[pos.first][pos.second - 1] == 0) {
                            posStack.push(pair<int, int>(pos.first, pos.second - 1));
                            continue;
                        } else {
                            maxNeighbors = max(maxNeighbors, memo[pos.first][pos.second - 1]);
                        }
                    }

                    if (pos.first < matrix.size() - 1 && matrix[pos.first + 1][pos.second] < matrix[pos.first][pos.second]) {
                        if (memo[pos.first + 1][pos.second] == 0) {
                            posStack.push(pair<int, int>(pos.first + 1, pos.second));
                            continue;
                        } else {
                            maxNeighbors = max(maxNeighbors, memo[pos.first + 1][pos.second]);
                        }
                    }

                    if (pos.second < matrix[0].size() - 1 && matrix[pos.first][pos.second + 1] < matrix[pos.first][pos.second]) {
                        if (memo[pos.first][pos.second + 1] == 0) {
                            posStack.push(pair<int, int>(pos.first, pos.second + 1));
                            continue;
                        } else {
                            maxNeighbors = max(maxNeighbors, memo[pos.first][pos.second + 1]);
                        }
                    }

                    memo[pos.first][pos.second] = maxNeighbors + 1;
                    posStack.pop();
                }

                longestPath = max(longestPath, memo[x][y]);
            }
        }

        return longestPath;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> matrix = {
            {9, 9, 4},
            {6, 6, 8},
            {2, 1, 1}
    };

    std::cout << sol.longestIncreasingPath(matrix) << std::endl;
    return 0;
}
