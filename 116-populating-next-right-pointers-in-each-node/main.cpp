#include <iostream>
#include <queue>

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
            : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution_bfs {
public:
    Node* connect(Node* root) {
        queue<Node*> nodeQueue;
        nodeQueue.push(root);

        while (!nodeQueue.empty()) {
            int currentQueueSize = nodeQueue.size();

            for(int x = 0; x < currentQueueSize; x++) {
                Node* currentNode = nodeQueue.front();
                nodeQueue.pop();

                if(x < currentQueueSize-1) currentNode->next = nodeQueue.front(); //Only set next if not last node on row

                if(currentNode->left != nullptr) nodeQueue.push(currentNode->left);
                if(currentNode->right != nullptr) nodeQueue.push(currentNode->right);
            }
        }

        return root;
    }
};



class Solution_1 {
public:
    Node* connect(Node* root) {
        preOrderTraversel(root);
        return root;
    }

    void preOrderTraversel(class Node* node)
    {
        if (node == NULL) {
            return;
        }

        if(node->left != NULL && node->right != NULL) {
            node->left->next = node->right;
        }
        if(node->next != NULL && node->right != NULL && node->right->next == NULL) {
            node->right->next = node->next->left;
        }

        preOrderTraversel(node->left);
        preOrderTraversel(node->right);
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
