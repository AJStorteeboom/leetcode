#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>


using namespace std;

class Solution {
public:

    //BFS
    bool validPath_1(int n, vector<vector<int>> &edges, int source, int destination) {
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


    //DFS
    bool validPath_2(int n, vector<vector<int>> &edges, int source, int destination) {
        unordered_map<int, vector<int>> graph;

        //Add both edges because the graph is bi-directional
        for (vector<int> edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        unordered_set<int> visited;
        stack<int> stack;

        stack.push(source);

        while (!stack.empty()) {
            int currentEdge = stack.top();
            visited.insert(currentEdge);
            stack.pop();

            if (currentEdge == destination) return true;

            for (int edge : graph[currentEdge]) {
                if (visited.find(edge) == visited.end()) stack.push(edge);
            }
        }

        return false;
    }
};

// Test Case
int main() {
    Solution sol;

    vector<vector<int>> edges = {
            {0,7},
            {0,8},
            {6,1},
            {2,0},
            {0,4},
            {5,8},
            {4,7},
            {1,3},
            {3,5},
            {6,5}
    };

    cout << sol.validPath_2(10, edges, 7, 5) << endl;

    return 0;
}
