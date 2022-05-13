#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution {
public:
    //DFS - 9 ms
    bool canVisitAllRooms_dfs(vector<vector<int>>& rooms) {
        stack<int> keyStack;
        unordered_set<int> roomVisited;
        roomVisited.insert(0);

        for(int key : rooms[0]) {
            keyStack.push(key);
            roomVisited.insert(key);
        }

        int totalRooms = rooms.size();
        int currentRoomsVisited = 1;

        while (!keyStack.empty() && currentRoomsVisited < totalRooms) {
            int key = keyStack.top();
            keyStack.pop();
            currentRoomsVisited++;

            for(int key : rooms[key]) {
                if(roomVisited.find(key) == roomVisited.end()) {
                    roomVisited.insert(key);
                    keyStack.push(key);
                }
            }
        }

        return currentRoomsVisited == totalRooms;
    }

    //BFS - 16ms
    bool canVisitAllRooms_bfs(vector<vector<int>>& rooms) {
        queue<int> keyQueue;
        unordered_set<int> roomVisited;
        roomVisited.insert(0);

        for(int key : rooms[0]) {
            keyQueue.push(key);
            roomVisited.insert(key);
        }

        int totalRooms = rooms.size();
        int currentRoomsVisited = 1;

        while (!keyQueue.empty() && currentRoomsVisited < totalRooms) {
            int key = keyQueue.front();
            keyQueue.pop();
            currentRoomsVisited++;

            for(int key : rooms[key]) {
                if(roomVisited.find(key) == roomVisited.end()) {
                    roomVisited.insert(key);
                    keyQueue.push(key);
                }
            }
        }

        return currentRoomsVisited == totalRooms;
    }
};

int main() {
    vector<vector<int>> rooms = {
            {1,3},{3,0,1},{2},{0}
    };

    Solution sol;

    std::cout << sol.canVisitAllRooms_bfs(rooms) << std::endl;
    std::cout << sol.canVisitAllRooms_dfs(rooms) << std::endl;
    return 0;
}
