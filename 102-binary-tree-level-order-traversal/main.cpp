#include <iostream>
#include <vector>
#include <queue>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        if(root == nullptr) return {};
        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);
        vector<vector<int>> result;

        while (!nodeQueue.empty()) {
            int currentQueueSize = nodeQueue.size();

            vector<int> rowResult;

            for(int x = 0; x < currentQueueSize; x++) {
                rowResult.push_back(nodeQueue.front()->val);

                if(nodeQueue.front()->left != nullptr) nodeQueue.push(nodeQueue.front()->left);
                if(nodeQueue.front()->right != nullptr) nodeQueue.push(nodeQueue.front()->right);

                nodeQueue.pop();
            }

            result.push_back(rowResult);
        }

        return result;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
