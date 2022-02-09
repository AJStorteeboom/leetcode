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

int sumEvenGrandparent(TreeNode* root) {
	queue<TreeNode*> nodeQueue;
	nodeQueue.push(root);

	int currentSum = 0;

	while (!nodeQueue.empty()) {
		TreeNode* node = nodeQueue.front();
		nodeQueue.pop();

		bool isEven = node->val % 2 == 0;

		if(node->right != nullptr) {
			nodeQueue.push(node->right);
			if(node->right->right != nullptr) {
				if(isEven) currentSum += node->right->right->val;
			}
			if(node->right->left != nullptr) {
				if(isEven) currentSum += node->right->left->val;
			}
		}

		if(node->left != nullptr) {
			nodeQueue.push(node->left);
			if(node->left->right != nullptr) {
				if(isEven) currentSum += node->left->right->val;
			}
			if(node->left->left != nullptr) {
				if(isEven) currentSum += node->left->left->val;
			}
		}
	}

	return currentSum;
}


int main() {
	TreeNode treeNode1 = TreeNode(6);
	TreeNode treeNode2 = TreeNode(7);
	TreeNode treeNode3 = TreeNode(8);
	TreeNode treeNode4 = TreeNode(2);
	TreeNode treeNode5 = TreeNode(7);
	TreeNode treeNode6 = TreeNode(1);
	TreeNode treeNode7 = TreeNode(3);
	TreeNode treeNode8 = TreeNode(9);
	TreeNode treeNode9 = TreeNode(1);
	TreeNode treeNode10 = TreeNode(4);
	TreeNode treeNode11 = TreeNode(5);

//	treeNode1.left = &treeNode2;
//	treeNode1.right = &treeNode3;
//	treeNode2.left = &treeNode4;
//	treeNode2.right = &treeNode5;
//	treeNode3.left = &treeNode6;
//	treeNode3.right = &treeNode7;
//	treeNode4.left = &treeNode8;
//	treeNode5.left = &treeNode9;
//	treeNode5.right = &treeNode10;
//	treeNode7.right = &treeNode11;

	std::cout << sumEvenGrandparent(&treeNode1) << std::endl;
	return 0;
}
