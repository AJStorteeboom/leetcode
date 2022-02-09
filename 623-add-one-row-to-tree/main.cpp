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


TreeNode* addOneRow(TreeNode* root, int val, int depth) {
	if(depth ==1) {
		auto* treeNode = new TreeNode(val);
		treeNode->left = root;
		return treeNode;
	}

	queue<pair<TreeNode*, int>> nodeQueue;
	nodeQueue.push(pair<TreeNode*, int>(root, 1));

	while (!nodeQueue.empty()) {
		pair<TreeNode*, int> treeElement = nodeQueue.front();
		nodeQueue.pop();

		if(treeElement.second == depth-1) {
			auto* newLeftNode = new TreeNode(val);
			auto* newRightNode = new TreeNode(val);
			if(treeElement.first->left != nullptr) newLeftNode->left = treeElement.first->left;
			if(treeElement.first->right != nullptr) newRightNode->right = treeElement.first->right;
			treeElement.first->left = newLeftNode;
			treeElement.first->right = newRightNode;
		} else {
			if(treeElement.first->left != nullptr) nodeQueue.push(pair<TreeNode*, int>(treeElement.first->left, treeElement.second+1));
			if(treeElement.first->right != nullptr) nodeQueue.push(pair<TreeNode*, int>(treeElement.first->right, treeElement.second+1));
		}
	}

	return root;
}

int main() {
	TreeNode node1 = TreeNode(4);
	TreeNode node2 = TreeNode(2);
	TreeNode node3 = TreeNode(6);
	TreeNode node4 = TreeNode(3);
	TreeNode node5 = TreeNode(1);
	TreeNode node6 = TreeNode(5);

	node1.left = &node2;
	node1.right = &node3;
	node2.left = &node4;
	node2.right = &node5;
	node3.left = &node6;


	TreeNode* root = addOneRow(&node1, 1, 2);

	return 0;
}
