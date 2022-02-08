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


bool hasPathSum(TreeNode* root, int targetSum) {
	queue<pair<TreeNode*, int>> queue;
	queue.push(pair<TreeNode*, int>(root, targetSum-root->val));

	while (!queue.empty()) {
		pair<TreeNode*, int> queueElement = queue.front();

		if(queueElement.second == 0 && queueElement.first->left == nullptr && queueElement.first->right == nullptr) return true;
		if(queueElement.first->left != nullptr) queue.push(pair<TreeNode*, int>(queueElement.first->left, queueElement.second-queueElement.first->left->val));
		if(queueElement.first->right != nullptr) queue.push(pair<TreeNode*, int>(queueElement.first->right, queueElement.second-queueElement.first->right->val));

		queue.pop();
	}

	return false;
}


int main() {

	TreeNode treeNode1 = TreeNode(5);
	TreeNode treeNode2 = TreeNode(4);
	TreeNode treeNode3 = TreeNode(8);
	TreeNode treeNode4 = TreeNode(11);
	TreeNode treeNode5 = TreeNode(13);
	TreeNode treeNode6 = TreeNode(4);
	TreeNode treeNode7 = TreeNode(7);
	TreeNode treeNode8 = TreeNode(2);
	TreeNode treeNode9 = TreeNode(1);

	treeNode1.left = &treeNode2;
	treeNode1.right = &treeNode3;

	treeNode2.left = &treeNode4;

	treeNode3.left = &treeNode5;
	treeNode3.right = &treeNode6;

	treeNode4.left = &treeNode7;
	treeNode4.right = &treeNode8;

	treeNode6.right = &treeNode9;


	std::cout << hasPathSum(&treeNode1, 22) << std::endl;
	return 0;
}
