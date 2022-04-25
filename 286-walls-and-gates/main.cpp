#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

class Solution {
public:


    void wallsAndGates(vector<vector<int>>& rooms) {
        int xasSize = rooms.size();
        int yasSize = rooms[0].size();

        for(int x = 0; x < xasSize; x++) {
            for(int y = 0; y < yasSize; y++) {
                //Skip if current location is not a gate.
                // This is because we want to do a BFS with the gate as starting point so we can increase our step size and update the value of the current location in the BFS.
                if(rooms[x][y] != 0) continue; //Wall or room

                queue<pair<int,int>> locations;
                locations.push(pair<int,int>(x,y));

                int steps = 0;

                while (!locations.empty()) {
                    int currentLocationSize = locations.size();

                    for(int locationIt = 0; locationIt < currentLocationSize; locationIt++) {
                        pair<int,int> currentLocation = locations.front();
                        locations.pop();

                        //Only add to the BFS queue if it is in borders and our current number of steps +1 is smaller than the value of the room.
                        //This covers the non-visited rooms (INF) and the rooms that already have been visited but can be reached in a smaller amount of steps
                        if(currentLocation.first < xasSize-1 && steps+1 < rooms[currentLocation.first+1][currentLocation.second]) {
                            rooms[currentLocation.first+1][currentLocation.second] = steps+1;
                            locations.push(pair<int,int>(currentLocation.first+1, currentLocation.second));
                        }
                        if(currentLocation.first > 0 && steps+1 < rooms[currentLocation.first-1][currentLocation.second]) {
                            rooms[currentLocation.first-1][currentLocation.second] = steps+1;
                            locations.push(pair<int,int>(currentLocation.first-1, currentLocation.second));
                        }
                        if(currentLocation.second < yasSize-1 && steps+1 < rooms[currentLocation.first][currentLocation.second+1]) {
                            rooms[currentLocation.first][currentLocation.second+1] = steps+1;
                            locations.push(pair<int,int>(currentLocation.first, currentLocation.second+1));
                        }
                        if(currentLocation.second > 0 && steps+1 < rooms[currentLocation.first][currentLocation.second-1]) {
                            rooms[currentLocation.first][currentLocation.second-1] = steps+1;
                            locations.push(pair<int,int>(currentLocation.first, currentLocation.second-1));
                        }
                    }

                    steps++;
                }
            }
        }
    }

    int const INF = 2147483647;

    //Solution from discuss section https://leetcode.com/problems/walls-and-gates/discuss/72745/Java-BFS-Solution-O(mn)-Time
    //Oil stain solution
    //Start at the gates and populate each room that is INF, further
    //Works because of BFS. The first oil stain that arrives at the INF room, has the shortest path.
    void wallsAndGates1(vector<vector<int>>& rooms) {
        if (rooms.empty() || rooms[0].empty()) return;
        queue<pair<int,int>> queue;
        
        for (int i = 0; i < rooms.size(); i++) {
            for (int j = 0; j < rooms[0].size(); j++) {
                if (rooms[i][j] == 0) queue.push(pair<int,int>(i,j));
            }
        }

        while (!queue.empty()) {
            pair<int,int> top = queue.front();
            queue.pop();
            
            int row = top.first, col = top.second;
            if (row > 0 && rooms[row - 1][col] == INF) {
                rooms[row - 1][col] = rooms[row][col] + 1;
                queue.push(pair<int,int>(row - 1, col));
            }
            if (row < rooms.size() - 1 && rooms[row + 1][col] == INF) {
                rooms[row + 1][col] = rooms[row][col] + 1;
                queue.push(pair<int,int>(row + 1, col));
            }
            if (col > 0 && rooms[row][col - 1] == INF) {
                rooms[row][col - 1] = rooms[row][col] + 1;
                queue.push(pair<int,int>(row, col - 1));
            }
            if (col < rooms[0].size() - 1 && rooms[row][col + 1] == INF) {
                rooms[row][col + 1] = rooms[row][col] + 1;
                queue.push(pair<int,int>(row, col + 1));
            }
        }
    }
};

int main() {
    Solution sol;
    
    vector<vector<int>> grid = {
            {2147483647,-1,0,2147483647},{2147483647,2147483647,2147483647,-1},{2147483647,-1,2147483647,-1},{0,-1,2147483647,2147483647}
    };
    
    sol.wallsAndGates(grid);
    return 0;
}
