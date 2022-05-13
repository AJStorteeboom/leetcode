#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>

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

    //BFS
    vector<vector<int>> verticalOrder(TreeNode *root) {
        if(root == nullptr) return {};

        map<int, vector<int>> mapResult;

        queue<pair<int, TreeNode*>> nodeQueue;
        nodeQueue.push(pair<int,TreeNode*>(0, root));
        mapResult[0].push_back(root->val);

        while (!nodeQueue.empty()) {
            pair<int, TreeNode*> stackElement = nodeQueue.front();
            nodeQueue.pop();

            if(stackElement.second->left != nullptr) {
                nodeQueue.push(pair<int,TreeNode*>(stackElement.first - 1, stackElement.second->left));
                mapResult[stackElement.first - 1].push_back(stackElement.second->left->val);
            }
            if(stackElement.second->right != nullptr) {
                nodeQueue.push(pair<int,TreeNode*>(stackElement.first + 1, stackElement.second->right));
                mapResult[stackElement.first + 1].push_back(stackElement.second->right->val);
            }
        }

        vector<vector<int>> vectorResult;

        for (auto const& x : mapResult) {
            vectorResult.push_back(x.second);
        }

        return vectorResult;
    }
};

int main() {

    TreeNode tr1 = TreeNode(3);
    TreeNode tr2 = TreeNode(9);
    TreeNode tr3 = TreeNode(8);
    TreeNode tr4 = TreeNode(4);
    TreeNode tr5 = TreeNode(0);
    TreeNode tr6 = TreeNode(1);
    TreeNode tr7 = TreeNode(7);

    tr1.left = &tr2;
    tr1.right = &tr3;

    tr2.left = &tr4;
    tr2.right = &tr5;

    tr3.left = &tr6;
    tr3.right = &tr7;

    Solution sol;
    sol.verticalOrder(&tr1);


    std::cout << "Hello, World!" << std::endl;
    return 0;
}
