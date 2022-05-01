#include <iostream>
#include <vector>

#include <queue>
#include <stack>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int numIslands_BFS(vector<vector<char>> &grid) {
        int xasSize = grid.size();
        int yasSize = grid[0].size();
        int visited[301][301] = {0};
        int currentNumberOfIslands = 0;

        for (int x = 0; x < xasSize; x++) {
            for (int y = 0; y < yasSize; y++) {
                //Skip cases. If it is water, it is not important and if it is land we already visited, it is already counted.
                if (grid[x][y] != '1') continue;
                if (visited[x][y] == 1) continue;

                currentNumberOfIslands++;

                queue<pair<int, int>> queue;
                queue.push(pair<int, int>(x, y));

                //Explore island
                while (!queue.empty()) {
                    pair<int, int> currentLocation = queue.front();
                    queue.pop();

                    //Check for every possibility if it is also land and if it hasn't been visited yet.
                    if (currentLocation.second < yasSize - 1 && grid[currentLocation.first][currentLocation.second + 1] == '1' && visited[currentLocation.first][currentLocation.second + 1] == 0) {
                        visited[currentLocation.first][currentLocation.second + 1] = 1;
                        queue.push(pair<int, int>(currentLocation.first, currentLocation.second + 1));
                    }
                    if (currentLocation.second > 0 && grid[currentLocation.first][currentLocation.second - 1] == '1' && visited[currentLocation.first][currentLocation.second - 1] == 0) {
                        visited[currentLocation.first][currentLocation.second - 1] = 1;
                        queue.push(pair<int, int>(currentLocation.first, currentLocation.second - 1));
                    }
                    if (currentLocation.first < xasSize - 1 && grid[currentLocation.first + 1][currentLocation.second] == '1' && visited[currentLocation.first + 1][currentLocation.second] == 0) {
                        visited[currentLocation.first + 1][currentLocation.second] = 1;
                        queue.push(pair<int, int>(currentLocation.first + 1, currentLocation.second));
                    }
                    if (currentLocation.first > 0 && grid[currentLocation.first - 1][currentLocation.second] == '1' && visited[currentLocation.first - 1][currentLocation.second] == 0) {
                        visited[currentLocation.first - 1][currentLocation.second] = 1;
                        queue.push(pair<int, int>(currentLocation.first - 1, currentLocation.second));
                    }
                }
            }
        }

        return currentNumberOfIslands;
    }

    //DFS
    int numIslands_DFS(vector<vector<char>> &grid) {
        int xasSize = grid.size();
        int yasSize = grid[0].size();
        int visited[301][301] = {0};
        int currentNumberOfIslands = 0;

        for (int x = 0; x < xasSize; x++) {
            for (int y = 0; y < yasSize; y++) {
                //Skip cases. If it is water, it is not important and if it is land we already visited, it is already counted.
                if (grid[x][y] != '1') continue;
                if (visited[x][y] == 1) continue;

                currentNumberOfIslands++;

                stack<pair<int, int>> stack;
                stack.push(pair<int, int>(x, y));

                //Explore island
                while (!stack.empty()) {
                    pair<int, int> currentLocation = stack.top();
                    stack.pop();

                    //Check for every possibility if it is also land and if it hasn't been visited yet.
                    if (currentLocation.second < yasSize - 1 && grid[currentLocation.first][currentLocation.second + 1] == '1' && visited[currentLocation.first][currentLocation.second + 1] == 0) {
                        visited[currentLocation.first][currentLocation.second + 1] = 1;
                        stack.push(pair<int, int>(currentLocation.first, currentLocation.second + 1));
                    }
                    if (currentLocation.second > 0 && grid[currentLocation.first][currentLocation.second - 1] == '1' && visited[currentLocation.first][currentLocation.second - 1] == 0) {
                        visited[currentLocation.first][currentLocation.second - 1] = 1;
                        stack.push(pair<int, int>(currentLocation.first, currentLocation.second - 1));
                    }
                    if (currentLocation.first < xasSize - 1 && grid[currentLocation.first + 1][currentLocation.second] == '1' && visited[currentLocation.first + 1][currentLocation.second] == 0) {
                        visited[currentLocation.first + 1][currentLocation.second] = 1;
                        stack.push(pair<int, int>(currentLocation.first + 1, currentLocation.second));
                    }
                    if (currentLocation.first > 0 && grid[currentLocation.first - 1][currentLocation.second] == '1' && visited[currentLocation.first - 1][currentLocation.second] == 0) {
                        visited[currentLocation.first - 1][currentLocation.second] = 1;
                        stack.push(pair<int, int>(currentLocation.first - 1, currentLocation.second));
                    }
                }
            }
        }

        return currentNumberOfIslands;
    }
};


int main() {
    Solution solution;

    vector<vector<char>> grid = {
    };

    std::cout << solution.numIslands(grid) << std::endl;
    return 0;
}
