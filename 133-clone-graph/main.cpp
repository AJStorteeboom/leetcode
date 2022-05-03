#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
private:
    unordered_map<int, Node*> nodeMap;

public:
    //8 ms
    Node* cloneGraph_dfs(Node* node) {
        if(node == nullptr) return nullptr;

        unordered_set<int> visited;
        stack<Node*> stack;

        stack.push(node);
        visited.insert(node->val);

        while (!stack.empty()) {
            Node* currentNode = stack.top();
            stack.pop();

            //Get existing or create new node with given value
            Node* copyCurrentNode = getNode(currentNode->val);

            for(Node* neighbor : currentNode->neighbors) {
                //Check if we already visited the neighbor node. If not, add it to the queue
                if(visited.find(neighbor->val) == visited.end()) {
                    stack.push(neighbor);
                    visited.insert(neighbor->val);
                }

                //Get existing or create new node with given value
                Node* neighborNode = getNode(neighbor->val);

                //Add neighborNode to neighbors list
                copyCurrentNode->neighbors.push_back(neighborNode);
            }
        }

        //Return the node with value of the node given as parameter
        return nodeMap[node->val];
    }

    //18 ms
    Node* cloneGraph_bfs(Node* node) {
        if(node == nullptr) return nullptr;

        unordered_set<int> visited;
        queue<Node*> queue;

        queue.push(node);
        visited.insert(node->val);

        while (!queue.empty()) {
            Node* currentNode = queue.front();
            queue.pop();

            //Get existing or create new node with given value
            Node* copyCurrentNode = getNode(currentNode->val);

            for(Node* neighbor : currentNode->neighbors) {
                //Check if we already visited the neighbor node. If not, add it to the queue
                if(visited.find(neighbor->val) == visited.end()) {
                    queue.push(neighbor);
                    visited.insert(neighbor->val);
                }

                //Get existing or create new node with given value
                Node* neighborNode = getNode(neighbor->val);

                //Add neighborNode to neighbors list
                copyCurrentNode->neighbors.push_back(neighborNode);
            }
        }

        //Return the node with value of the node given as parameter
        return nodeMap[node->val];
    }

    Node* getNode(int val) {
        //Check if we already have a node with current value. If so, return it otherwise create a new node and store it in the map.
        if(nodeMap.find(val) != nodeMap.end()) {
            return nodeMap[val];
        } else {
            Node* newNode = new Node(val);
            nodeMap.insert(pair<int,Node*>(val, newNode));
            return newNode;
        }
    }
};

int main() {
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);

    vector<Node*> neighborsNode1 = {node2, node4};
    vector<Node*> neighborsNode2 = {node1, node3};
    vector<Node*> neighborsNode3 = {node2, node4};
    vector<Node*> neighborsNode4 = {node1, node3};

    node1->neighbors = neighborsNode1;
    node2->neighbors = neighborsNode2;
    node3->neighbors = neighborsNode3;
    node4->neighbors = neighborsNode4;


    Solution sol;

    std::cout << sol.cloneGraph_bfs(node1) << std::endl;
    std::cout << sol.cloneGraph_dfs(node1) << std::endl;
    return 0;
}
