#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    bool validPath(int n, vector<vector<int>> &edges, int source, int destination) {
        unordered_map<int, vector<int>> graph;

        //Add both edges because the graph is bi-directional
        for (vector<int> edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        unordered_set<int> visited;
        queue<int> queue;

        queue.push(source);

        while (!queue.empty()) {
            int currentEdge = queue.front();
            visited.insert(currentEdge);
            queue.pop();

            if (currentEdge == destination) return true;

            for (int edge : graph[currentEdge]) {
                if (visited.find(edge) == visited.end()) queue.push(edge);
            }
        }

        return false;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
