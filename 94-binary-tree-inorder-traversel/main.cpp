#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>

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
    vector<int> sol;

    /*
     * My recursive solution
     */
    void recursive(TreeNode *node) {
        if (node == nullptr) return;
        recursive(node->left);
        sol.push_back(node->val);
        cout << node->val << endl;
        recursive(node->right);
    }

    vector<int> inorderTraversal(TreeNode *root) {
        recursive(root);
        return sol;
    }


    /*
     * My Solution with a stack. It needs a visited set to avoid adding the same nodes over and over again.
     */
    vector<int> inorderTraversal_stack(TreeNode *root) {
        if (root == nullptr) return {};
        stack<TreeNode *> stack;
        stack.push(root);

        vector<int> result = {};
        unordered_set<TreeNode *> visited;

        while (!stack.empty()) {
            TreeNode *node = stack.top();

            if (node->left != nullptr && visited.find(node->left) == visited.end()) {
                stack.push(node->left);
                visited.insert(node->left);
            } else {
                stack.pop();
                result.push_back(node->val);
                if (node->right != nullptr && visited.find(node->right) == visited.end()) {
                    stack.push(node->right);
                    visited.insert(node->right);
                }
            }
        }

        return result;
    }


    /*
     * Solution of leetcode. This one doesn't need a visited array or something like that.
     */
    vector<int> inorderTraversal_solution(TreeNode *root) {
        if (root == nullptr) return {};

        stack<TreeNode *> stack;
        TreeNode *curr = root;
        vector<int> result = {};

        while (curr != nullptr || !stack.empty()) {
            while(curr != nullptr) {
                stack.push(curr);
                curr = curr->left;
            }

            curr = stack.top();
            stack.pop();

            result.push_back(curr->val);
            curr = curr->right;
        }

        return result;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
