#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <stack>

using namespace std;

class Solution {
public:
    unordered_map<int, vector<int>> graph;
    int memo[10001] = {0};
    int destination;
    unordered_set<int> visited; //keep track of current path to detect cycles

    bool dfs(int currentNode) {
        if (currentNode == destination) return true; //Return true if destination is reached
        if (graph[currentNode].empty()) return false; //Return false if currentNode is empty and is not the destination node

        for (int connectedNode : graph[currentNode]) {
            if (memo[connectedNode] != 0) continue;
            if (visited.find(connectedNode) != visited.end()) return false; //Return false if we detect a cycle

            memo[connectedNode] = 1;

            visited.insert(connectedNode); //Remember that we visited the current node
            if (!dfs(connectedNode)) return false; //Return false if
            visited.erase(connectedNode); //Forget visited node
        }

        //Return true if every connected node returned true
        return true;
    }

    bool leadsToDestination(int n, vector<vector<int>> &edges, int source, int destination) {
        this->destination = destination;
        for (vector<int> edge : edges) graph[edge[0]].push_back(edge[1]);
        if (!graph[destination].empty()) return false;

        return dfs(source);
    }
};


int main() {
    Solution sol;

    vector<vector<int>> nodes = {
            {0, 1},
            {0, 2},
            {1, 3},
            {2, 3}
    };

    std::cout << sol.leadsToDestination(4, nodes, 0, 3) << std::endl;
    return 0;
}
