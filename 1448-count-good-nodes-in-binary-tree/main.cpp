#include <iostream>
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

int goodNodes(TreeNode *root) {
	if(root->left == nullptr && root->right == nullptr) return 1;


	queue<pair<TreeNode*, int>> nodeQueue;
	if(root->left != nullptr) nodeQueue.push(pair<TreeNode*, int>(root->left, root->val));
	if(root->right != nullptr) nodeQueue.push(pair<TreeNode*, int>(root->right, root->val));

	int goodNodes = 1;

	while(!nodeQueue.empty()) {
		pair<TreeNode*, int> nodeElement = nodeQueue.front();
		nodeQueue.pop();

		if(nodeElement.first->val >= nodeElement.second) goodNodes++;
		if(nodeElement.first->left != nullptr) nodeQueue.push(pair<TreeNode*, int>(nodeElement.first->left, max(nodeElement.second, nodeElement.first->val)));
		if(nodeElement.first->right != nullptr) nodeQueue.push(pair<TreeNode*, int>(nodeElement.first->right, max(nodeElement.second, nodeElement.first->val)));
	}

	return goodNodes;
}

int main() {
	std::cout << "Hello, World!" << std::endl;
	return 0;
}
